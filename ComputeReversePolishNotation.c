#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "list.h"
#include <stdbool.h>
#define ElemType int

#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S){
    S->top = -1;
}

int compute_reverse_polish_notation(char *str)
{
    Stack st;
    init_stack(&st);
    int cur = 0;
    while (cur < strlen(str))
    {
        if (str[cur] >= '0' && str[cur] <= '9')
        {
            int endPos = cur, mul = 1, num = 0;
            while (str[endPos] != ' ' && str[endPos] != '\0')
            {
                endPos++;
            }
            for (int i = endPos - 1; i >= cur; i--)
            {
                num += (str[i] - '0') * mul;
                mul *= 10;
            }
            push(&st, num);
            cur = endPos + 1;
            continue;
        }
        int x, y;
        pop(&st, &y);
        pop(&st, &x);
        switch (str[cur])
        {
            case '+':
                push(&st, x + y);
                break;
            case '-':
                push(&st, x - y);
                break;
            case '*':
                push(&st, x * y);
                break;
            case '/':
                push(&st, x / y);
                break;
            case '%':
                push(&st, x % y);
                break;
        }
        cur += 2;
    }
    int ans;
    pop(&st, &ans);
    return ans;
}