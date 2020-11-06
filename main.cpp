#include <iostream>
#include "Session.h"
#include <fstream>
#include "json.hpp"
using json=nlohmann::json;
using namespace std;


int main(int argc, char** argv){

    /*if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }*/
//    Session sess(argv[1]);    argv1 will be json input file path
//      Session sess("config1.json");
//    sess.simulate();
    ifstream input("config1.json");
    json j;
    input>>j;
    cout<< j["tree"]<< endl;


    return 0;
}
