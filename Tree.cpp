//
// Created by spl211 on 06/11/2020.
//
#include "Graph.h"
#include "Tree.h"
#include "Session.h"
using namespace std;

Tree::Tree(int rootLabel): node(rootLabel), children(){}
Tree::Tree(const Tree& tree):children(tree.children),node(tree.node){}
Tree:: ~Tree(){
    if(!children.empty())
        for(Tree* tree:children)
            delete tree;
}
//Tree:: ~Tree() {if(children) delete children;}
//Tree:: Tree(const Tree& other){
//    node=other.node;
//    children=other.children;
//}
CycleTree::CycleTree(int rootLabel, int currCycle) :Tree(rootLabel),currCycle(currCycle){}
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}
RootTree::RootTree(int rootLabel) :Tree(rootLabel){}

void Tree::addChild(const Tree &child) {children.push_back(new Tree(child));}

Tree* Tree::createTree(const Session &session, int rootLabel) {}

int Tree::traceTree() {return 0;}


Tree* BFS(int root,Session session) {
    Tree *tree = Tree::createTree(session, root);
    int numOfV = session.getGraph().numberOfVertices();
    bool *isVisited = new bool[numOfV];
    for (int i = 0; i < numOfV; i++)
        isVisited[i] = false;
    vector<int> myqueue;
    myqueue.push_back((*tree).Getnode());
    isVisited[root] = true;
    while (myqueue.size()!=0) {
        int node = myqueue.at(0);
        myqueue.erase(myqueue.begin());
        isVisited[node] = true;
        vector<int> neighbors = session.getGraph().getEdges()[node];
        for (int neighbor=0 ;neighbor<= numOfV; neighbor++){
            if (neighbors.at(neighbor)==1 & !isVisited[neighbor]){
                Tree* curr = Tree::createTree(session,neighbor);
                tree->addChild(*curr);
                myqueue.push_back(neighbor);
            }
        }
    }
    return tree;
}