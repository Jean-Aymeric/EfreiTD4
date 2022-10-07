//
// Created by JAD on 07/10/2022.
//

#include "bufferNode.h"

BufferNode* createEmptyBufferNode() {
    BufferNode* newBufferNode = malloc(sizeof(BufferNode));
    if (newBufferNode != NULL) {
        newBufferNode->head = NULL;
    }
    return newBufferNode;
}

Node* popFromBufferNode(BufferNode* bufferNode) {
    if (bufferNode == NULL) {
        return NULL;
    }
    if (isBufferNodeEmpty(*bufferNode)) {
        return NULL;
    }
    NodeCell* temporaryBufferNode = bufferNode->head;
    bufferNode->head = temporaryBufferNode->next;

    return temporaryBufferNode->value;
}

NodeCell* createNodeCellFromValue(Node* value) {
    NodeCell* newNodeCell = malloc(sizeof(NodeCell));
    if (newNodeCell != NULL) {
        newNodeCell->value = value;
        newNodeCell->next = NULL;
    }
    return newNodeCell;
}

void pushInBufferNode(BufferNode* bufferNode, Node* value) {
    if (bufferNode != NULL) {
        if (isBufferNodeEmpty(*bufferNode)) {
            bufferNode->head = createNodeCellFromValue(value);
        } else {
            NodeCell* temporaryBufferNode = bufferNode->head;
            while(temporaryBufferNode->next != NULL) {
                temporaryBufferNode = temporaryBufferNode->next;
            }
            temporaryBufferNode->next = createNodeCellFromValue(value);
        }
    }
}

bool isBufferNodeEmpty(BufferNode bufferNode) {
    return bufferNode.head == NULL;
}