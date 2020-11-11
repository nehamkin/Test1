#include <iostream>
#include <fstream>
#include "Session.h"
#include "json.hpp"
#include "Tree.h"
#include "Agent.h"
#include <queue>
#include "Graph.h"
//Tree* BFS(int root,Session session) {
//    Tree *tree = Tree::createTree(session, root);
//    int numOfV = session.getGraph().numberOfVertices();
//    vector<bool> isVisited;
//    vector<bool> inQueue;
//    for (int i = 0; i < numOfV; i++) {
//        isVisited.push_back(false);
//        inQueue.push_back(false);
//    }
//    queue<Tree*> myQueue;
//    myQueue.push(tree);
//    isVisited.at(root) = true;
//    while (!myQueue.empty()) {
//        Tree* curr1 = myQueue.front();
//        myQueue.pop();
//        int currentNode =curr1->getNode();
//        isVisited.at(currentNode) = true;
//        vector<int> neighbors = session.getGraph().getEdges()[currentNode];
//        for (int neighbor=0 ;neighbor< numOfV; neighbor++){
//            if (neighbors.at(neighbor)==1 & !isVisited.at(neighbor) & !inQueue.at(neighbor)){
//                Tree* curr2 = Tree::createTree(session,neighbor);
//                curr1->addChild(curr2);
//                myQueue.push(curr2);
//                inQueue.at(neighbor) = true;
//            }
//        }
//    }
//    return tree;
//}
//--------------------------------------------------------

//------------------------------------------------------
int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    Session sess(argv[1]);
    Tree* t0 = Tree::createTree(sess, 0);
    Tree* t1 = Tree::createTree(sess, 1);
    Tree* t2 = Tree::createTree(sess, 2);
    Tree* t3 = Tree::createTree(sess, 3);
    Tree* t4 = Tree::createTree(sess, 4);
    Tree* t5 = Tree::createTree(sess, 5);
    Tree* t6 = Tree::createTree(sess, 6);
    Tree* t7 = Tree::createTree(sess, 7);
    t0->addChild(t1);
    t0->addChild(t2);
    t0->addChild(t3);
    t1->addChild(t4);
    t1->addChild(t5);
    t3->addChild(t6);
    bool i = false;
    vector<Tree*> v = t0->getChildren();
    v.pop_back();

    //t0->clearpointers();
    while (!i){
        MaxRankTree* m0 = new MaxRankTree(10);
        delete m0;
        i = true;
    }


//    sess.simulate();
    return 0;
}
