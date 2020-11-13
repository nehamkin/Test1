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
    Tree(Tree&& tree);
    Tree& operator=(const Tree& tree);
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
    void clearpointers();

protected:
    int node;
    std::vector<Tree*> children; //vectors are allocated on the heap
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
//    ~CycleTree();
//    CycleTree(const CycleTree & other);
//    CycleTree& operator=(const CycleTree &other);
    virtual int traceTree();
    virtual Tree* clone() const;
    void printTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
//    ~MaxRankTree();
    virtual int traceTree();
    virtual Tree* clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
//    ~RootTree();
    virtual int traceTree();
    virtual Tree* clone() const;
};



#endif
