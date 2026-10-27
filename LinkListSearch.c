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

int lnk_search(LinkList L, int k, ElemType* p_ele)
{
    Node *a[1005];
    int siz = 0;
    Node *cur = L;
    while (cur -> next != NULL)
    {
        siz++;
        a[siz] = cur -> next;
        cur = cur -> next;
    }
    if (k > siz)
    {
        return 0;
    }
    p_ele = &(a[siz - k + 1] -> data);
    return 1;
}