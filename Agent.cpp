//
// Created by spl211 on 06/11/2020.
//

#include "Agent.h"

Agent::Agent() {}
ContactTracer::ContactTracer() {}
string ContactTracer:: mytype(){return "Contacttracer :D"; }

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}
string Virus::mytype() {return "Virus :(";}