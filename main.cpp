#include <iostream>
#include "Session.h"
#include <fstream>
#include "json.hpp"
using json=nlohmann::json;
using namespace std;

int main(int argc, char** argv){
    cout<<"Testing123"<<endl;
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }

    Session sess(argv[1]);
//    sess.simulate();
//    return 0;
}
