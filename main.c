#include <stdio.h>
#include "tree.h"
#include "bufferNode.h"

int main() {
    Tree *myTree = createTreeFromNode(createNode(1));

    myTree->root->right = createNode(3);
    myTree->root->left = createNode(2);

    myTree->root->right->right = createNode(7);
    myTree->root->right->left = createNode(6);

    myTree->root->left->right = createNode(5);
    myTree->root->left->left = createNode(4);

    myTree->root->right->right->right = createNode(8);

    displayTree(*myTree);
    printf("cc\n");
    displayHorizontallyTree(*myTree);
    return 0;
}
