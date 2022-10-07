//
// Created by JAD on 05/10/2022.
//

#ifndef TD4_TREE_H
#define TD4_TREE_H
#include <stdlib.h>
#include "bufferNode.h"
#include "node.h"
typedef struct Tree {
    Node *root;
} Tree;

Node *createNode(int value);

Tree *createTree();

Tree* createTreeFromNode(Node *node);

void displayTree(Tree tree);

int maxInTree(Tree tree);

int sumFromTree(Tree tree);

int getNbNodesInTree(Tree tree);

float getAvgFromTree(Tree tree);

int getHeightFromTree(Tree tree);

int countNbOccurrencesInTree(Tree tree, int value);

void displayHorizontallyTree(Tree tree);

void displayPrefixTree(Tree tree);
void displayInfixTree(Tree tree);
void displayPostfixTree(Tree tree);

#endif //TD4_TREE_H
