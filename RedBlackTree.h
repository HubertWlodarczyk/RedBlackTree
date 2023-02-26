//
// Created by huber on 25.02.2023.
//

#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H
#include "NodeRBT.h"
class NodeRBT;
class RedBlackTree {
    NodeRBT* root;
    void RotationL(NodeRBT*);
    void RotationR(NodeRBT*);
    void Repair(NodeRBT*);
public:
    RedBlackTree();
    ~RedBlackTree();
    void Add(int);
    void Show();
    NodeRBT *getUncle(NodeRBT *inNode) ;
    NodeRBT *getGrandParent(NodeRBT *pRbt);
};


#endif //REDBLACKTREE_REDBLACKTREE_H
