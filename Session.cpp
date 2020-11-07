//
// Created by spl211 on 07/11/2020.
//

#include "Session.h"
#include "Agent.h"

Session::Session(const std::string &path) {
    ifstream i(path);
    json j;
    j << i;
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
    g=graph;
//    ----Agents----
    for(auto& elem: j["agents"]){
        if(elem[0]=="V")
            agents.push_back(new Virus(elem[1]));
        else
            agents.push_back(new ContactTracer);
    }
}
void Session::printGraph() { cout<< g.edges << endl;}
void Session::printAgents() {cout<<"agents"<<endl; for(auto elem:agents){cout<< typeid(elem).name() <<endl;}}
void Session::printType() {cout<< treeType << endl;}