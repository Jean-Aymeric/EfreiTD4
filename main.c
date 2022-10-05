#include <stdio.h>
#include "tree.h"

int main() {
    Tree *myTree = createTreeFromNode(createNode(42));

    myTree->root->right = createNode(-1);
    myTree->root->left = createNode(7);

    myTree->root->right->right = createNode(39);
    myTree->root->right->left = createNode(55);

    myTree->root->left->right = createNode(78);
    myTree->root->left->left = createNode(999);

    myTree->root->right->right->right = createNode(2);

    displayTree(*myTree);

    printf("\n%d %d %d", maxInTree(*myTree), sumFromTree(*myTree), getNbNodesInTree(*myTree));

    printf("\n%f", getAvgFromTree(*myTree));

    printf("\n%d", getHeightFromTree(*myTree));
    return 0;
}
