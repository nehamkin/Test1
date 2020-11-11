
#include "Session.h"
# include "Agent.h"

bool Session::condition() {
    vector<vector<int>> components = g.connectedComponents();
    for(vector<int> v: components){
        bool allRed= red[v.front()];
        bool allNotYellow= yellow[v.front()];
        for(int x: v){
            if(red[x]!=allRed | yellow[x]!=allNotYellow)
                return true;
        }
    }
    return false;
}

void Session::simulate() {
    while(condition()){
        for(int i=0;i<agentSize;i++){
            agents[i]->act(*this);
        }
        agentSize=agents.size();
    }
}