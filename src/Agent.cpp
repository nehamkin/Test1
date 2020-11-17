//
// Created by spl211 on 06/11/2020.
//
#include "../Include/Tree.h"
#include "../Include/Agent.h"


Tree* BFS(int root,Session session) {
    Tree *tree = Tree::createTree(session, root);
    int numOfV = session.getGraph().numberOfVertices();
    vector<bool> isVisited;
    vector<bool> inQueue;
    for (int i = 0; i < numOfV; i++) {
        isVisited.push_back(false);
        inQueue.push_back(false);
    }
    queue<Tree*> myQueue;
    myQueue.push(tree);
    isVisited.at(root) = true;
    while (!myQueue.empty()) {
        Tree* curr1 = myQueue.front();
        myQueue.pop();
        int currentNode =curr1->getNode();
        isVisited.at(currentNode) = true;
        vector<int> neighbors = session.getGraph().getEdges()[currentNode];
        for (int neighbor=0 ;neighbor< numOfV; neighbor++){
            if (((neighbors.at(neighbor)==1) & (!isVisited.at(neighbor))) & !inQueue.at(neighbor)){
                Tree* curr2 = Tree::createTree(session,neighbor);
                curr1->addChild(curr2);
                myQueue.push(curr2);
                inQueue.at(neighbor) = true;
            }
        }
    }
    return tree;
}

Agent::Agent() {}
Agent::Agent(const Agent &agent) {}
Agent:: ~Agent(){};
string Agent::mytype() {return "agent";}
ContactTracer::ContactTracer() {}
string ContactTracer:: mytype(){return "Contacttracer :D"; }

Agent* Virus::clone() const {
    Agent* agent = new Virus(nodeInd);
    return agent;
}

Agent* ContactTracer::clone() const {Agent * agent = new ContactTracer(); return agent;} // will never be used since there is no need to add a new CT to the agent list in session

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}
string Virus::mytype() {return "Virus :(";}
//-------------ACT-------------------------------------------------
void Virus::act(Session &session) {
    if(!session.isRed(nodeInd)){        //make sure virus is active
        session.setRed(nodeInd);
        session.enqueueInfected(nodeInd);
    }
    vector<int> neighbors = session.getGraph().getNeighborsOf(nodeInd);
    bool infectedNeighbor = false;
    for (unsigned int i = 0;(i<neighbors.size()) & (!infectedNeighbor);i++ ){               //checks node's neighbors
       int neighbor = neighbors.at(i);
        if (!session.isYellow(neighbor)){
           session.setYellow(neighbor);
           Virus *virus = new Virus(neighbor);
           Agent* curr=virus;                      //create a new virus
           session.addAgent(*curr);                 // clones curr and stores clone on heap , curr never gets deleted
           delete virus;
           infectedNeighbor = true;
       }
    }
}
void ContactTracer::act(Session &session) {
    if(!session.isInfectedQempty()){
        Tree* tree = BFS(session.dequeueInfected(),session);
        int toDetach = tree->traceTree();
        delete tree;
        session.detachVertex(toDetach);
    }
}