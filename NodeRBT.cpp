//
// Created by huber on 25.02.2023.
//

#include "NodeRBT.h"
NodeRBT::NodeRBT(int inValue,char inColor){
    this->value=inValue;
    this->color=inColor;
    this->lChild= nullptr;
    this->rChild= nullptr;
    this->parent=nullptr;
}
NodeRBT::~NodeRBT() = default;
