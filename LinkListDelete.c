#include <stdio.h>
#include <stdlib.h>
// #include "list.h"
#define ElemType int

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    Node *st = NULL, *cur = L;
    while (st == NULL && cur -> next != NULL)
    {
        if (cur -> next -> data > mink)
        {
            st = cur;
        }
        cur = cur -> next;
    }
    while (1)
    {
        if (cur -> data >= maxk)
        {
            st -> next = cur;
            break;
        }
        Node *tmp = cur;
        cur = cur -> next;
        free(tmp);
        if (cur == NULL)
        {
            st -> next = cur;
            break;
        }
    }
}