//
// Created by JAD on 12/10/2022.
//

#ifndef TD4_BST_H
#define TD4_BST_H
#include "tree.h"
#include <stdio.h>
typedef Tree BST;

void insertValueInBST(BST* bst,int value);
void rotateLeft(BST *bst, int valueToRotate);


#endif //TD4_BST_H
