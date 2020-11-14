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
  /*  Virus v1(4);
    Virus v2(v1);
    Agent* a1 = &v1;
    Agent *a2= &v2;
    CycleTree *ct1=new CycleTree(3,5);
    CycleTree ct2(*ct1);
    ct1->printTree();
    ct2.printTree();
    Tree *t1= ct1;
    Tree* t2=&ct2;
    t1->printTree();
    t2->printTree();
    CycleTree ct3(10,12);
    ct3.printTree();
    delete ct1;
    ct3 = ct2;
    ct3 = CycleTree(100,1000);
    ct3.printTree();
//    ct3 = &ct1;


//    a1->print();
//    a2->print();


    Session sess1(sess);
    sess.printGraph();
    sess.simulate();
    cout<<endl;
    sess.printGraph();
    cout<<"sess1:"<<endl;
    sess1.printGraph();
    sess1=sess;
    cout<<endl;
    sess1.printGraph();
    sess1 =(Session(argv[1]));
    cout<<endl;
    sess1.printGraph(); */


    Tree* t0 = Tree::createTree(sess, 0);
    Tree* t1 = Tree::createTree(sess, 1);
    Tree* t2 = Tree::createTree(sess, 2);
    Tree* t3 = Tree::createTree(sess, 3);
    t0->addChild(t1); t0->addChild(t2); t1->addChild(t3);

    MaxRankTree* m0 = new MaxRankTree(0);
    MaxRankTree* m1 = new MaxRankTree(1);
    MaxRankTree* m2 = new MaxRankTree(2);
    MaxRankTree* m3 = new MaxRankTree(3);
    m0->addChild(m1); m0->addChild(m2); m1->addChild(m3);

    RootTree* r0 = new RootTree(0);
    RootTree* r1 = new RootTree(1);
    RootTree* r2 = new RootTree(2);
    RootTree* r3 = new RootTree(3);
    r0->addChild(r1); r0->addChild(r2);r1->addChild(r3);

    CycleTree* c0 = new CycleTree(0,4);
    CycleTree* c1 = new CycleTree(1,4);
    CycleTree* c2 = new CycleTree(2,4);
    CycleTree* c3 = new CycleTree(3,4);
    c0->addChild(c1); c0->addChild(c2);c1->addChild(c3);

   Session s2 = Session(sess);
   sess.setYellow(4);
   sess.enqueueInfected(8);
   s2 = sess;

    delete c0; delete t0; delete r0; delete m0;






  //  delete t0; delete m0; delete r0; delete c0;

    return 0;
}
