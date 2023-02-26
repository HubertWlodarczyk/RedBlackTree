//
// Created by huber on 25.02.2023.
//
#ifndef REDBLACKTREE_NODERBT_H
#define REDBLACKTREE_NODERBT_H
#include "RedBlackTree.h"

class NodeRBT {
    friend class RedBlackTree;
    int value;
    char color;
    NodeRBT* lChild;
    NodeRBT* rChild;
    NodeRBT* parent;
    NodeRBT(int inValue=0,char inColor='r');
    ~NodeRBT();
};


#endif //REDBLACKTREE_NODERBT_H
