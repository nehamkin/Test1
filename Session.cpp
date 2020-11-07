//
// Created by spl211 on 06/11/2020.
//
#include "Session.h"
 Session::Session(const std::string &path) {
     ifstream i(path);
     json j;
     j << i;
     //----Tree Type----
     if(j["tree"]=='M')
         treeType=MaxRank;
     else if(j["tree"]=='R')
         treeType=Root;
     else
         treeType=Cycle;
//     ----end Tree Type ----

}






