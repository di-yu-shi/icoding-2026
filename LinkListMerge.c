#include <stdio.h>
#include <stdlib.h>
// #include "list.h"
#define ElemType int
#define MIN(x, y) ((x) < (y) ? (x) : (y))

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_merge(LinkList A, LinkList B, LinkList C)
{
    int m = 1, n = 1;
    Node *curA = A -> next, *curB = B -> next;
    while (curA -> next != NULL)
    {
        m++;
        curA = curA -> next;
    }
    while (curB -> next != NULL)
    {
        n++;
        curB = curB -> next;
    }
    curA = A -> next;
    curB = B -> next;
    for (int i = 1; i <= MIN(n, m); i++)
    {
        Node *nxtA = curA -> next, *nxtB = curB -> next;
        curA -> next = curB;
        curB -> next = nxtA;
        if (m < n && i == m)
        {
            curB -> next = nxtB;
        }
        curA = nxtA;
        curB = nxtB;
    }
    C -> next = A -> next;
}