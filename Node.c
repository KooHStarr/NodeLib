#include "Node.h"

static Node * head = NULL;
static Node * back = NULL;

/*
alloc a single node and init all fields
 */
Node * privateAlloc(DATA data)
{
    Node * list = (Node *) malloc(sizeof(Node));
    list->data = data;
    list->next = NULL;
    return list;
}


/*
alloc the main node
 */
void createNewList(DATA data)
{
    head = privateAlloc(data);
}


/*
attach a node to linked list
 */
void pushBack(DATA data)
{
    if (head->next == NULL)
    {
        head->next = privateAlloc(data);
        back = head->next;

    } else {
        Node * temp = privateAlloc(data);
        back->next = temp;
        back = temp;
    }
}


/*
delete linked list from memory
 */
void freeList(FRCallback c)
{
    Node * curr = head;
    Node * temp;

    while (curr)
    {
        temp = curr->next;
        c(curr->data);
        free(curr);
        curr = temp;
    }

    head = back = NULL;
}

/*
iterate though all nodes from head and do the callback with current node
 */
void iterateWithCallbackH(NDCallback c)
{
    Node * curr;
    for (curr = head; curr != NULL; curr = curr->next)
    {
        c(curr);
    }
}


/*
get the node as in array
 */
Node* getNodeByIndex(int index)
{
    Node * curr;
    int i;

    for (curr = head, i = 0; curr != NULL; curr = curr->next, i++)
    {
        if (i == index)
            return curr;
    }

    return NULL;
}

/*
sort our list with simple bubble sort
*/

void sortList(SortCallback callback)
{
    Node * prev, *curr, *sort, *curv, *prem, *mini;

    for (prev = curr = head; curr->next != NULL; prev = curr, curr = curr->next)
    {
        prem = prev;
        mini = curr;

        for (sort = curr, curv = curr->next; curv != NULL; sort = curv, curv = curv->next)
        {
            if(callback(curv, mini))
            {
                prem = sort;
                mini = curv;
            }

            if (mini == curr)
                continue;

            if (curr == head)
                head = mini;
            else
                prev->next = mini;

            prem->next = mini->next;
            mini->next = curr;
            curr = mini;
        }
    }
}
