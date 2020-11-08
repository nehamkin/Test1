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

Tree* Tree::createTree(const Session &session, int rootLabel) {

}
Tree* BFS(int rootLabel, Session session){
    Tree* tree=new Tree(rootLabel);
    int numOfV=session.getGraph().numberOfVertices();
    bool* isVisited= new bool[numOfV];
    for(int i=0; i<numOfV;i++)
        isVisited[i]=false;
    vector<int> myqueue ;
    myqueue.push_back(rootLabel);
    isVisited[rootLabel] = tree;
    for(int node = 0; myqueue.size()!=0;){

    }
}