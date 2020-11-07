//
// Created by spl211 on 06/11/2020.
//
#include "Session.h"
 Session::Session(const std::string &path):g(),treeType(),agents() {
     ifstream i(path);
     json j;
     j << i;
     //----Tree Type----
     string type=j["tree"];
     if(type=="M")
         treeType=MaxRank;
     else if(type=="R")
         treeType=Root;
     else
         treeType=Cycle;
//     ----end Tree Type ----

}






