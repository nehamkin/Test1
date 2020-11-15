#include <iostream>
#include <fstream>
#include "../Include/Session.h"
#include "../Include/json.hpp"
#include "../Include/Tree.h"
#include "../Include/Agent.h"
#include <queue>
#include "../Include/Graph.h"


#define JSON_PATH "output.json"

using namespace std;

int tree_exp1(){
    MaxRankTree t(1);
    MaxRankTree t2(2);
    t2.addChild(MaxRankTree(3));
    t2.addChild(MaxRankTree(4));
    t2.addChild(MaxRankTree(5));
    t.addChild(t2);
    t.addChild(MaxRankTree(6));
    return t.traceTree();
}


int main(int argc, char** argv) {
    nlohmann::json j;
    Session sess("/home/spl211/Desktop/Test1/config4.json");
    sess.simulate();
    sess.output();
}
