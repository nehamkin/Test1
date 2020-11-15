//
// Created by spl211 on 06/11/2020.
//
#include "Graph.h"
#include "Tree.h"
#include "Session.h"
#include <queue>
using namespace std;

Tree::Tree(int rootLabel): node(rootLabel), children(){}
Tree:: ~Tree(){
    clearpointers();
    children.clear();
}
Tree::Tree(const Tree& tree):node(tree.node){ //looks good
    for (int i =0; i<tree.children.size(); i++){
        Tree* curr = tree.children.at(i)->clone();
        children.push_back(curr);
    }
}
Tree& Tree::operator=(const Tree& tree){
    if(this!=&tree & &tree != nullptr){
        clearpointers();
        node = tree.node;
        for (int i =0; i<tree.children.size(); i++){
            Tree* curr = tree.children.at(i)->clone();
            children.push_back(curr);
        }
    }
    return *this;
}
Tree::Tree(Tree&& tree): node(tree.node){ // looks good
    for (int i =0; i<tree.children.size(); i++){
        children.push_back(tree.children.at(i));
        tree.children.at(i) = nullptr;
    }
}
Tree & Tree::operator=(Tree &&tree) {
    if(this!=&tree) {
        clearpointers();
        node = tree.node;
        children = tree.children;
        for (int i = 0; i < tree.children.size(); i++) {
            tree.children.at(i) = nullptr;
        }
    }
    return *this;
}

void Tree::clearpointers() {
    if (&children != nullptr) {
        for (auto child: children) {
            delete child;
        }
        children.clear();
    }
}

vector<Tree*> Tree::getChildren() const {return children;}

//------------constructors for sub classes -------------------------
CycleTree::CycleTree(int rootLabel, int currCycle) :Tree(rootLabel),currCycle(currCycle){}

MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

RootTree::RootTree(int rootLabel) :Tree(rootLabel){}
//------------create tree ------------------------------------------
Tree* Tree::createTree(const Session &session, int rootLabel) {
    Tree* tree;
    switch(session.getTreeType()){
        case Cycle:
            tree = new CycleTree(rootLabel,session.getCycle());
            break;

        case MaxRank:
            tree = new MaxRankTree(rootLabel);
            break;

        case Root:
            tree= new RootTree(rootLabel);
            break;
    }
    return tree;

}

//----------------clones for add child -------------
Tree* CycleTree::clone() const{
    Tree* pclone = new CycleTree(*this);
    return pclone;
}

Tree* MaxRankTree::clone() const {
    Tree* pclone = new MaxRankTree(*this);
    return pclone;
}

Tree* RootTree:: clone() const{
    Tree* pclone = new RootTree(*this);
    return pclone;
}
//--------------Add Child-------------------------------------
void Tree::addChild(const Tree &child) {
    Tree* toAdd = child.clone();
    children.push_back(toAdd);

}

void Tree::addChild(Tree *child) {
    children.push_back(child);
}
//----------------Trace Tree----------------------------------
int MaxRankTree::traceTree() {
    int output = getNode(); // the number of the node with the most children
    int max = getChildren().size(); // the most children a node has so far
    Tree* t;  // the child that we will be working on
    queue<Tree*> q; // queue so that i can enter nodes by level and from left to right
    q.push(this);
    while(!q.empty()){
        t=q.front(); // t is the child that we want to work on
        q.pop();
        if(t->getChildren().size()>max){ // if this tree has the most children then he is the node to return so far
            max=t->getChildren().size();
            output=t->getNode();
        }
        for(int i=0; i<t->getChildren().size();i++){ //  adds the next level of children
            q.push(t->getChildren()[i]);
        }
    }
    return output;
}

int CycleTree::traceTree(){
    int ans = this->getNode();
    Tree* curr = this;
    for(int counter = 0 ; counter<currCycle & curr!=0; counter++) {
        if (curr->getChildren().size()!= 0){
            curr = curr->getChildren().at(0);
            ans = curr->getNode();
        }
    }
    return ans;
}
int RootTree::traceTree() {return getNode();}




