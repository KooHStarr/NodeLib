#ifndef NODE_H
#define NODE_H

#include <malloc.h>

typedef void* DATA;

typedef struct Node
{
    DATA data;
    struct Node * next;
} Node;

typedef void (*NDCallback)(Node*);
typedef void (*FRCallback)(DATA);
typedef int (*SortCallback)(Node*, Node*);

static struct Node * head;
static struct Node * back;

Node * privateAlloc(DATA data);
void createNewList(DATA data);
void pushBack(DATA data);
void freeList(FRCallback c);
void iterateWithCallbackH(NDCallback c);
Node* getNodeByIndex(int index);
void sortList(SortCallback c);

#endif
