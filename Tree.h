#ifndef TREE_H_
#define TREE_H_
using namespace std;
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    //    -----RULE OF 5--------------------------------------
    virtual ~Tree();                    //destructor
    Tree(const Tree& other);            //copy constructor
    Tree& operator=(const Tree& tree);  //copy assignment
    Tree(Tree&& tree);                  //move constructor
    Tree& operator=(Tree&& tree);       //move assignment
    void clearpointers();               //deletes all the resources **is used in rule of 5
    //    ----Add Child---------------------------------------
    void addChild(const Tree& child);
    void addChild(Tree* child);
//    -----Important Tree functions--------------------------------
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree* clone() const=0;
//    -------Getters------------------------------------------
    int getNode() const{return node;}
    vector<Tree*> getChildren() const;

protected:
    int node;
    std::vector<Tree*> children; //vectors are allocated on the heap
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual Tree* clone() const;
    void printTree();
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
