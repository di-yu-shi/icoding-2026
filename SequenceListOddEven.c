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

void odd_even(SeqList *L)
{
    int l = 0, r = L -> last + 1;
    while (l < r)
    {
        if (L -> elem[l] % 2 == 0)
        {
            ElemType tmp = L -> elem[l];
            L -> elem[l] = L -> elem[r - 1];
            L -> elem[r - 1] = tmp;
            r--;
        }
        else
        {
            l++;
        }
    }
}