#include <iostream>
#include <fstream>
#include "Session.cpp"
#include "json.hpp"



int main(int argc, char** argv){

    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
  // Session sess(argv[1]);
//      Session sess("config1.json");
//    sess.simulate();
    ifstream i(argv[1]);
    json j2;
    j2<<i;
    cout<<j2["tree"]<<endl;

    return 0;
}
