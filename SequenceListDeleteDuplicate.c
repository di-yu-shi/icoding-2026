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

void del_dupnum(SeqList *L)
{
    ElemType lastElem = L -> elem[0];
    int lastElemPos = 0;
    for (int i = 1; i <= L -> last; i++)
    {
        if (L -> elem[i] != lastElem)
        {
            L -> elem[lastElemPos + 1] = L -> elem[i];
            lastElem = L -> elem[i];
            lastElemPos++;
        }
    }
    L -> last = lastElemPos;
}