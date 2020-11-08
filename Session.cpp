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

Graph Session::getGraph() const {return g;}


void Session::printGraph() {
    const vector<vector<int>> matrix= g.getEdges();
    for(int i=0;i<matrix.size();i++){
        cout<<""<<endl;
        for(int j=0;j<matrix.size();j++)
            cout<<matrix[i][j]<<ends;}
}
void Session::printAgents() {int i = 1 ; for(auto elem:agents){cout<<"agent number "<<i <<" is a "<<  elem->mytype() <<endl;i++;}}
void Session::printType() {if (treeType == MaxRank) cout<<"Max rank tree"<<endl; else if (treeType == Cycle) cout<<"Cycle tree"<<endl; else cout<<"root tree"<<endl ;}