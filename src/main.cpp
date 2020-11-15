#include <iostream>
#include <fstream>
#include "../Include/Session.h"
#include "../Include/json.hpp"
#include "../Include/Tree.h"
#include "../Include/Agent.h"
#include <queue>
#include "Include/Graph.h"



int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    Session sess(argv[1]);
    sess.simulate();
    sess.output();


    return 0;
}
