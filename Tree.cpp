//
// Created by spl211 on 06/11/2020.
//

#include "Tree.h"
using namespace std;

Tree::Tree(int rootLabel): node(rootLabel), children(){}
Tree::Tree(const Tree& tree):children(tree.children),node(tree.node){}
//Tree:: ~Tree() {if(children) delete children;}
//Tree:: Tree(const Tree& other){
//    node=other.node;
//    children=other.children;
//}
CycleTree::CycleTree(int rootLabel, int currCycle) :Tree(rootLabel),currCycle(currCycle){}
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}
RootTree::RootTree(int rootLabel) :Tree(rootLabel){}

void Tree::addChild(const Tree &child) {children.push_back(new Tree(child));}