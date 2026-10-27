#include <stdio.h>
#include <stdlib.h>
// #include "list.h"
#define ElemType int
#define MAXSIZE 1000005

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void del_x2y(SeqList *L, ElemType x, ElemType y)
{
    int curLast = -1;
    for (int i = 0; i <= L -> last; i++)
    {
        if (!(L -> elem[i] >= x && L -> elem[i] <= y))
        {
            curLast++;
            L -> elem[curLast] = L -> elem[i];
        }
    }
    L -> last = curLast;
}