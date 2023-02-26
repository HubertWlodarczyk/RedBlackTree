#include <iostream>
#include <cmath>
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    this->root = nullptr;
}

RedBlackTree::~RedBlackTree() {
    delete this->root;
}

void RedBlackTree::Add(int inValue) {
    NodeRBT *newNode = new NodeRBT(inValue);
    if (this->root == nullptr) {
        this->root = newNode;
        this->root->color = 'b';
        return;
    }
    NodeRBT *newNodePlace = this->root;
    NodeRBT *previousNode = nullptr;
    char side;
    while (newNodePlace != nullptr) {
        if (newNodePlace->value == inValue) return;
        previousNode = newNodePlace;
        if (newNodePlace->value > inValue) {
            newNodePlace = newNodePlace->lChild;
            side = 'l';
            continue;
        }
        newNodePlace = newNodePlace->rChild;
        side = 'r';
    }
    newNodePlace = newNode;
    newNodePlace->parent = previousNode;
    if (side == 'l') previousNode->lChild = newNodePlace;
    else previousNode->rChild = newNodePlace;
    Repair(newNodePlace);
}

void RedBlackTree::Repair(NodeRBT *inNode) {
    while (inNode->parent->color != 'b') {
        NodeRBT *uncle;
        NodeRBT *grandParent;
        char uncleColor;

        grandParent = getGrandParent(inNode);
        uncle = getUncle(inNode);
        if (uncle != nullptr)uncleColor = uncle->color;
        else uncleColor = 'b';

        if (uncleColor == 'r') {
            uncle->color = 'b';
            grandParent->color = 'r';
            inNode->parent->color = 'b';
            if (grandParent != this->root) {
                inNode = grandParent;
                continue;
            }
            grandParent->color = 'b';
            break;
        } else if (inNode == inNode->parent->lChild && inNode->parent == grandParent->rChild && uncleColor == 'b') {
            RotationR(inNode->parent);
            inNode = inNode->rChild;
        } else if (inNode == inNode->parent->rChild && inNode->parent == grandParent->lChild && uncleColor == 'b') {
            RotationL(inNode->parent);
            inNode = inNode->lChild;
        }

        uncle = getUncle(inNode);
        if (uncle != nullptr) uncleColor = uncle->color;
        else uncleColor = 'b';

        if (grandParent->rChild != nullptr && inNode == grandParent->rChild->rChild && uncleColor == 'b') {
            inNode->parent->color = 'b';
            grandParent->color = 'r';
            RotationL(grandParent);
        } else if (grandParent->lChild != nullptr && inNode == grandParent->lChild->lChild && uncleColor == 'b') {
            inNode->parent->color = 'b';
            grandParent->color = 'r';
            RotationR(grandParent);
        }
        break;
    }
}

NodeRBT *RedBlackTree::getUncle(NodeRBT *inNode) {
    NodeRBT *uncle = nullptr;
    if (inNode->parent->parent != nullptr) {
        if (inNode->parent == inNode->parent->parent->lChild) uncle = inNode->parent->parent->rChild;
        if (inNode->parent == inNode->parent->parent->rChild) uncle = inNode->parent->parent->lChild;
    }
    return uncle;
}

NodeRBT *RedBlackTree::getGrandParent(NodeRBT *pRbt) {
    NodeRBT *grandParent = nullptr;
    if (pRbt->parent != nullptr && pRbt->parent->parent != nullptr) grandParent = pRbt->parent->parent;
    return grandParent;
}

void RedBlackTree::RotationL(NodeRBT *inNode) {
    NodeRBT *rChild = inNode->rChild;

    inNode->rChild = rChild->lChild;
    if (inNode->rChild != nullptr)inNode->rChild->parent = inNode;

    rChild->parent = inNode->parent;
    if (rChild->parent != nullptr) {
        if (rChild->parent->lChild == inNode) rChild->parent->lChild = rChild;
        else rChild->parent->rChild = rChild;
    }
    inNode->parent = rChild;
    rChild->lChild = inNode;
    if (inNode == this->root) this->root = rChild;
}

void RedBlackTree::RotationR(NodeRBT *inNode) {
    NodeRBT *lChild = inNode->lChild;

    inNode->lChild = lChild->rChild;
    if (inNode->lChild != nullptr)inNode->lChild->parent = inNode;

    lChild->parent = inNode->parent;
    if (lChild->parent != nullptr) {
        if (lChild->parent->lChild == inNode) lChild->parent->lChild = lChild;
        else lChild->parent->rChild = lChild;

    }
    inNode->parent = lChild;
    lChild->rChild = inNode;
    if (inNode == this->root) this->root = lChild;
}

void RedBlackTree::Show() {
    if (this->root == nullptr) return;
    int treeHigh = 1;
    NodeRBT *pNode = this->root;
    while (pNode->lChild != nullptr) {
        pNode = pNode->lChild;
        treeHigh++;
    }
    int treeSize = 0;
    for (int i = 0; i < treeHigh + 3; i++) {
        treeSize += pow(2, i);
    }
    NodeRBT **quNodes = new NodeRBT *[treeSize];
    for (int i = 0; i < treeSize; i++) quNodes[i] = nullptr;
    int rNodes = 0;
    int wNodes = 0;
    quNodes[wNodes++] = this->root;
    do {
        std::cout << "Node has value: " << quNodes[rNodes]->value;
        if (quNodes[rNodes]->lChild != nullptr) {
            std::cout << "; left child: " << quNodes[rNodes]->lChild->value;
            quNodes[wNodes++] = quNodes[rNodes]->lChild;
        }
        if (quNodes[rNodes]->rChild != nullptr) {
            std::cout << "; right child: " << quNodes[rNodes]->rChild->value;
            quNodes[wNodes++] = quNodes[rNodes]->rChild;
        }
        if (quNodes[rNodes]->color == 'b') std::cout << "; and black color" << std::endl;
        else std::cout << "; and red color" << std::endl;
        rNodes++;
    } while (rNodes != wNodes);

}

