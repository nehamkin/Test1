#include <iostream>
#include <fstream>
#include "Session.h"
#include "json.hpp"
#include "Tree.h"
#include <queue>

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
            if (neighbors.at(neighbor)==1 & !isVisited.at(neighbor) & !inQueue.at(neighbor)){
                Tree* curr2 = Tree::createTree(session,neighbor);
                curr1->addChild(curr2);
                myQueue.push(curr2);
                inQueue.at(neighbor) = true;
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

   Session sess(argv[1]);
   Tree* tree= BFS(0, sess);
    tree->printTree();
    cout<<"the max tree is:"<<tree->traceTree()<<endl;


//    sess.simulate();
    return 0;
}
