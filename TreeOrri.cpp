//
// Created by spl211 on 08/11/2020.
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
//----------------constructors----------------------
CycleTree::CycleTree(int rootLabel, int currCycle) :Tree(rootLabel),currCycle(currCycle){}
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}
RootTree::RootTree(int rootLabel) :Tree(rootLabel){}







