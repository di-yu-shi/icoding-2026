#include <stdio.h>
#include <stdlib.h>
// #include "list.h"
#include <stdbool.h>
#define ElemType int

typedef struct _QueueNode {
    ElemType data;
    struct _QueueNode *next;
}LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue *LQ)
{
	if (LQ == NULL)
    {
        return false;
    }
    LinkQueueNode *head = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (head == NULL)
    {
        return false;
    }
    head -> next = head;
    *LQ = head;
    return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
	if (LQ == NULL)
    {
        return false;
    }
    LinkQueueNode *cur = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (cur == NULL)
    {
        return false;
    }
    cur -> data = x;
    cur -> next = (*LQ) -> next;
    (*LQ) -> next = cur;
    *LQ = cur;
    return true;
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
	if (LQ == NULL)
    {
        return false;
    }
    if ((*LQ) -> next == *LQ)
    {
        return false;
    }
    LinkQueueNode *top = (*LQ) -> next -> next;
    *x = top -> data;
    (*LQ) -> next -> next = top -> next;
    if (top -> next == top -> next -> next)
    {
        *LQ = top -> next;
    }
    free(top);
    return true;
}