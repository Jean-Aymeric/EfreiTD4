#include <stdio.h>
#include "tree.h"
#include "BST.h"
#include <time.h>
#include <stdlib.h>


int main() {
    srand( time( NULL ) );
   BST *bst=createTree();
   for(int i=0;i<100;i++){
       insertValueInBST(bst,rand()%8);
   }
    displayTree(*bst);
    rotateLeft(bst,bst->root->value);
    displayTree(*bst);
    return 0;
}
