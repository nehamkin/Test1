//
// Created by spl211 on 07/11/2020.
//

#include "../Include/Session.h"
#include "../Include/Agent.h"

//------------constructor------------------
Session::Session(const std::string &path):g(), treeType(), agents(), cycleNum(0),red(), yellow(), agentSize(), infectedQ() {
    ifstream i(path);
    json j;
   // j << i;
    i>>j;
    //----Tree Type----
    string type = j["tree"];
    if (type == "M")
        treeType = MaxRank;
    else if (type == "R")
        treeType = Root;
    else
        treeType = Cycle;


//    ---- Graph g ----
    vector<vector<int>> matrix = j["graph"];
    Graph graph(matrix);
    g = graph;
    int numOfV = g.numberOfVertices();
    for (int i = 0; i < numOfV; i++) {
        red.push_back(false);
        yellow.push_back(false);
    }
//    ----Agents----
    for (auto &elem: j["agents"]) {
        if (elem[0] == "V") {
        agents.push_back(new Virus(elem[1]));
        yellow[elem[1]]=true;
        }
        else
            agents.push_back(new ContactTracer);
    }
    agentSize=agents.size();
}
Session:: ~Session() {
        clear();
}
void Session::clear() {
    for (Agent *elem: agents) {
        delete elem;
    }
    agents.clear();
}
Session::Session(const Session &other):g(other.g), treeType(other.treeType), agents(), cycleNum(other.cycleNum),red(other.red), yellow(other.yellow), agentSize(other.agentSize), infectedQ(other.infectedQ){
    for (int i = 0; i<other.agentSize ;i++){
        Agent* curr = other.agents.at(i)->clone();
        agents.push_back(curr);
     }
}
Session& Session::operator=(const Session &other){
    if(this!=&other) {
        clear();
        treeType = other.treeType;
        g = other.g;
        cycleNum = other.cycleNum;
        agentSize = other.agentSize;
        yellow = other.yellow;
        red = other.red;
        infectedQ = other.infectedQ;
        for (int i = 0; i < other.agentSize; i++) {
            Agent *curr = other.agents.at(i)->clone();
            agents.push_back(curr);
        }
    }
    return *this;
}
Session::Session(Session && other): g(other.g), treeType(other.treeType), agents(), cycleNum(other.cycleNum),red(other.red), yellow(other.yellow), agentSize(other.agentSize), infectedQ(other.infectedQ){
    for (int i = 0; i< agentSize;i++){
        agents.push_back(other.agents.at(i));
        other.agents.at(i) = nullptr;
    }

}
Session& Session::operator=(Session &&other) {
    if(this!= &other) {
        clear();
        treeType = other.treeType;
        g = other.g;
        cycleNum = other.cycleNum;
        agentSize = other.agentSize;
        yellow = other.yellow;
        red = other.red;
        infectedQ = other.infectedQ;
        for (int i = 0; i< agentSize;i++){
            agents.push_back(other.agents.at(i));
            other.agents.at(i) = nullptr;
        }
        other.agents.clear();
    }
    return *this;
}
//----------------getters and setters -------------------
Graph Session::getGraph() const {return g;}
int Session::getCycle() const {return cycleNum;}
TreeType Session::getTreeType() const {return treeType;}
// --------------Red Yellow vector functions --------------
bool Session:: isRed(int x) const {return red[x];}
bool Session:: isYellow(int x) const {return yellow[x];}
bool Session::isInfectedQempty() {return infectedQ.empty();}
void Session::setRed(int toChange) {red[toChange]=true;}
void Session::setYellow(int toChange) {yellow[toChange]=true;}
//---------------NQ DQ -----------------------------------
void Session::enqueueInfected(int x) {infectedQ.push(x);}
int Session::dequeueInfected() {
    int x=infectedQ.front();
    infectedQ.pop();
    return x;
}
//-----------------------------------------------------
void Session::addAgent(const Agent &agent) {
    Agent *ag= agent.clone();
    agents.push_back(ag);
}
void Session::detachVertex(int v) {
    g.detachVertex(v);
}
// ----------------Simulate-------------------------------------
bool Session::condition() {
    vector<vector<int>> components = g.connectedComponents();
    for(vector<int> v: components){
        bool firstRed= red[v.front()];
        bool firstNotYellow= !yellow[v.front()]; // if vertex is not yellow thus he is blue
        for(int x: v){
            if((red[x]!=yellow[x])|((red[x]!=firstRed) | (!yellow[x]!=firstNotYellow))){ // if there is a red vertex in a component
                return true;
            }
        }
    }
    return false;
}
void Session::simulate() {
    agentSize = agents.size();
    while (condition()) {
        for (int i = 0; i < agentSize; i++) {
            agents[i]->act(*this);
        }
        cycleNum++;
        agentSize = agents.size();
    }
}
vector<int> Session::getInfected(){
    vector<int> output;
    for(unsigned int i = 0; i<red.size();i++){
        if(isRed(i))
            output.push_back(i);
    }
    return output;
}

void Session::output() {
    json j;
    j["infected"] = getInfected();
    j["graph"] = g.getEdges();
    ofstream o("output.json");
    o<<j<<endl;
}