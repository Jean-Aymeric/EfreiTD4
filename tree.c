//
// Created by JAD on 05/10/2022.
//

#include "tree.h"
#include <stdio.h>

#define max(a, b) (a>=b?a:b)

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

Tree *createTree() {
    Tree *newTree = malloc(sizeof(Tree));
    if (newTree != NULL) {
        newTree->root = NULL;
    }
    return newTree;
}

Tree *createTreeFromNode(Node *node) {
    Tree *newTree = createTree();
    if (newTree != NULL) {
        newTree->root = node;
    }
    return newTree;
}

void displayNode(Node *node) {
    if (node != NULL) {
        printf("%d(", node->value);
        displayNode(node->left);
        printf(", ");
        displayNode(node->right);
        printf(")");
    } else {
        printf("-");
    }
}

void displayTree(Tree tree) {
    displayNode(tree.root);
    printf("\n");
}

int maxInNode(Node *node) {
    int maximum = node->value;
    if (node->left != NULL) {
        maximum = max(maximum, maxInNode(node->left));
    }
    if (node->right != NULL) {
        maximum = max(maximum, maxInNode(node->right));
    }
    return maximum;
}

int sumFromNode(Node *node) {
    int sum = node->value;
    if (node->left != NULL) {
        sum += sumFromNode(node->left);
    }
    if (node->right != NULL) {
        sum += sumFromNode(node->right);
    }
    return sum;
}

int getNbNodesInNode(Node *node) {
    int nbNodes = 1;
    if (node->left != NULL) {
        nbNodes += getNbNodesInNode(node->left);
    }
    if (node->right != NULL) {
        nbNodes += getNbNodesInNode(node->right);
    }
    return nbNodes;
}

int maxInTree(Tree tree) {
    if (tree.root != NULL) {
        return maxInNode(tree.root);
    } else {
        return -99999999;
    }
}

int sumFromTree(Tree tree) {
    if (tree.root != NULL) {
        return sumFromNode(tree.root);
    } else {
        return 0;
    }
}

int getNbNodesInTree(Tree tree) {
    if (tree.root != NULL) {
        return getNbNodesInNode(tree.root);
    } else {
        return 0;
    }
}

int getSumAndNbNodesFromNode(Node *node, int *nbNodes) {
    int sum = node->value;
    (*nbNodes)++;
    if (node->left != NULL) {
        sum += getSumAndNbNodesFromNode(node->left, nbNodes);
    }
    if (node->right != NULL) {
        sum += getSumAndNbNodesFromNode(node->right, nbNodes);
    }
    return sum;
}

float getAvgFromTree(Tree tree) {
    int nbNodes = 0;
    if (tree.root != NULL) {
        return (float) getSumAndNbNodesFromNode(tree.root, &nbNodes) / (float) nbNodes;
    } else {
        return 0;
    }
}

int getHeightFromNode(Node *node) {
    int height = 0;
    if (node->left != NULL) {
        height = getHeightFromNode(node->left);
    }
    if (node->right != NULL) {
        height = max(height, getHeightFromNode(node->right));
    }
    return height + 1;
}

int getHeightFromTree(Tree tree) {
    if (tree.root != NULL) {
        return getHeightFromNode(tree.root);
    } else {
        return 0;
    }
}

int countNbOccurrencesInNode(Node *node, int value) {
    int nbOccurrences = (node->value == value) ? 1 : 0;
    if (node->left != NULL) {
        nbOccurrences += countNbOccurrencesInNode(node->left, value);
    }
    if (node->right != NULL) {
        nbOccurrences += countNbOccurrencesInNode(node->right, value);
    }
    return nbOccurrences;

}

int countNbOccurrencesInTree(Tree tree, int value) {
    if (tree.root != NULL) {
        return countNbOccurrencesInNode(tree.root, value);
    } else {
        return 0;
    }
}

void displayPrefixNode(Node *node) {
    printf("%d ", node->value);
    if (node->left != NULL) {
        displayPrefixNode(node->left);
    }
    if (node->right != NULL) {
        displayPrefixNode(node->right);
    }
}

void displayInfixNode(Node *node) {
    if (node->left != NULL) {
        displayInfixNode(node->left);
    }
    printf("%d ", node->value);
    if (node->right != NULL) {
        displayInfixNode(node->right);
    }
}

void displayPostfixNode(Node *node) {
    if (node->left != NULL) {
        displayPostfixNode(node->left);
    }
    if (node->right != NULL) {
        displayPostfixNode(node->right);
    }
    printf("%d ", node->value);
}

void displayPrefixTree(Tree tree) {
    if (tree.root != NULL) {
        displayPrefixNode(tree.root);
    }
    printf("\n");
}

void displayInfixTree(Tree tree) {
    if (tree.root != NULL) {
        displayInfixNode(tree.root);
    }
    printf("\n");
}

void displayPostfixTree(Tree tree) {
    if (tree.root != NULL) {
        displayPostfixNode(tree.root);
    }
    printf("\n");
}
void displayHorizontallyTree(Tree tree){
    BufferNode* file = createEmptyBufferNode();
    pushInBufferNode(file,tree.root);
    while (!isBufferNodeEmpty(file)){
        Node* temp = popFromBufferNode(file);
        if (temp->left != NULL) {
            pushInBufferNode(file,temp->left);
        }
        if (temp->right != NULL) {
            pushInBufferNode(file,temp->right);
        }
        printf("%d ",temp->value);

    }
}
