//
// Created by spl211 on 07/11/2020.
//

#include "Session.h"

Session::Session(const std::string &path) {
    ifstream i(path);
    json j;
    j << i;
    //----Tree Type----
    string type = j["tree"];
    if (type == "M")
        treeType = MaxRank;
    else if (type == "R")
        treeType = Root;
    else
        treeType = Cycle;
}