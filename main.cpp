#include <iostream>
#include "Session.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv){

    /*if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }*/
//    Session sess(argv[1]);    argv1 will be json input file path
      Session sess("config1.json");
//    sess.simulate();
    return 0;
}
