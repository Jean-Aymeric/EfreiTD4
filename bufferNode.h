//
// Created by JAD on 07/10/2022.
//

#ifndef TD4_BUFFERNODE_H
#define TD4_BUFFERNODE_H
#include "node.h"
#include "tree.h"
#include <stdbool.h>

typedef struct NodeCell {
    Node* value;
    struct NodeCell* next;
} NodeCell;

typedef struct BufferNode {
    NodeCell* head;
} BufferNode;

BufferNode* createEmptyBufferNode();
Node* popFromBufferNode(BufferNode* bufferNode);
void pushInBufferNode(BufferNode* bufferNode, Node* value);
bool isBufferNodeEmpty();

#endif //TD4_BUFFERNODE_H
