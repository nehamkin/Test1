//
// Created by spl211 on 06/11/2020.
//

#include "Agent.h"

void detach(Session sess, int toDetach){
    for(int i=0; i<sess.getGraph().getEdges().size(); i++){
        sess.getGraph().deleteEdge(toDetach,i);
    }
}
Agent::Agent() {}
string Agent::mytype() {return "agent";}
ContactTracer::ContactTracer() {}
string ContactTracer:: mytype(){return "Contacttracer :D"; }

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}
string Virus::mytype() {return "Virus :(";}
void Virus::act(Session &session) {
    if(!session.isRed(nodeInd)){        //make sure virus is active
        session.setRed(nodeInd);
        session.enqueueInfected(nodeInd);
    }
    vector<int> neighbors = session.getGraph().getNeighborsOf(nodeInd);
    bool infectedNeighbor = false;
    for (int i = 0;i<neighbors.size() & !infectedNeighbor; ){               //checks node's neighbors
       int neighbor = neighbors.at(i);
        if (!session.isYellow(neighbor)){
           session.setYellow(neighbor);
           Agent* curr = new Virus(neighbor);                               //create a new virus
           session.addAgent(*curr);
           infectedNeighbor = true;
       }
    }
}
void ContactTracer::act(Session &session) {}