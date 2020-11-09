//
// Created by spl211 on 09/11/2020.
//

#include "Talclass.h"

int CycleTree::traceTree(){
    int ans = this->getNode();
    CycleTree* curr = this;
    for(int counter = 0 ; counter<currCycle & curr!=0; counter++)
        curr = dynamic_cast<CycleTree *>(this->getChildren().at(0));
    return ans;
}