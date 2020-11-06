#include <iostream>
#include <fstream>
#include "Session.cpp"
#include "json.hpp"



int main(int argc, char** argv){

    /*if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }*/
//    Session sess(argv[1]);    argv1 will be json input file path
//      Session sess("config1.json");
//    sess.simulate();
    ifstream input("/home/spl211/Desktop/Test1/config1.json");
    json j;
    j << input;
    cout<< j << endl;


    return 0;
}
