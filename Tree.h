#ifndef TREE_H_
#define TREE_H_
using namespace std;
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    virtual ~Tree();
    Tree(const Tree& other);
    Tree& operator=(const Tree& tree);
    Tree(Tree&& tree);
    Tree& operator=(Tree&& tree);
    void addChild(const Tree& child);
    void addChild(Tree* child);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    int getNode() const{return node;}
    vector<Tree*> getChildren() const;
    virtual Tree* clone() const=0;
    void printTree();
    void printLevel(int level);

private:
    int node;
    std::vector<Tree*> children; //vectors are allocated on the heap
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual Tree* clone() const;
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

#endif
