#include <iostream>
#include <fstream>
#include "Session.h"
#include "json.hpp"
#include "Tree.h"

Tree* BFS(int root,Session session) {
    Tree *tree = Tree::createTree(session, root);
    int numOfV = session.getGraph().numberOfVertices();
    bool *isVisited = new bool[numOfV];
    for (int i = 0; i < numOfV; i++)
        isVisited[i] = false;
    vector<int> myqueue;
    myqueue.push_back((*tree).getNode());
    isVisited[root] = true;
    while (myqueue.size()!=0) {
        int node = myqueue.at(0);
        myqueue.erase(myqueue.begin());
        isVisited[node] = true;
        vector<int> neighbors = session.getGraph().getEdges()[node];
        for (int neighbor=0 ;neighbor< numOfV; neighbor++){
            if (neighbors.at(neighbor)==1 & !isVisited[neighbor]){
                Tree* curr = Tree::createTree(session,neighbor);
                tree->addChild(*curr);
                myqueue.push_back(neighbor);
            }
        }
    }
    return tree;
}
//--------------------------------------------------------

//------------------------------------------------------
int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    MaxRankTree *t0=new MaxRankTree(0);
    MaxRankTree *t1=new MaxRankTree(1);
    MaxRankTree *t2=new MaxRankTree(2);
    MaxRankTree *t3=new MaxRankTree(3);
    MaxRankTree *t4=new MaxRankTree(4);
    MaxRankTree *t5=new MaxRankTree(5);
    MaxRankTree *t6=new MaxRankTree(6);


   Session sess(argv[1]);
    Tree* tree= BFS(0, sess);
    tree->printTree();
    sess.printType();
    sess.printAgents();
    sess.printGraph();

//    sess.simulate();
    return 0;
}
