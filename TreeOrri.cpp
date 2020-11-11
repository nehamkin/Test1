
#include "Session.h"
# include "Agent.h"

bool Session::condition() {
    vector<vector<int>> components = g.connectedComponents();
    for(vector<int> v: components){
        bool firstRed= red[v.front()];
        bool firstNotYellow= !yellow[v.front()]; // if vertex is not yellow thus he is blue
        for(int x: v){
            if(red[x]!=firstRed | !yellow[x]!=firstNotYellow){ // if there is a red vertex in a component
                return true;
            }
        }
    }
    return false;
}

void Session::simulate() {
    for (int i = 0; i < agentSize; i++) {
        agents[i]->act(*this);

    }
    agentSize = agents.size();
    while (condition()) {
        for (int i = 0; i < agentSize; i++) {
            agents[i]->act(*this);
        }
        agentSize = agents.size();
    }
}