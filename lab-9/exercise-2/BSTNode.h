#ifndef BSTNODE_H
#define BSTNODE_H

struct BSTNode{
    int data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;

    BSTNode(){
        data = 0;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    BSTNode(int value){
        data = value;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

     BSTNode(int value, BSTNode* p){
        data = value;
        parent = p;
        left = nullptr;
        right = nullptr;
    }
};

#endif