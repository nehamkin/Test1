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
void Virus::act(Session &session) {}
void ContactTracer::act(Session &session) {}