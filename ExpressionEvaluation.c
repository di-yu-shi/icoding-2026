#include <stdio.h>

int main()
{
    float ans;
    scanf("%f", &ans);
    char op;
    float cur;
    while (scanf("%c%f", &op, &cur) != EOF)
    {
        switch (op)
        {
            case '+':
                ans += cur;
                break;
            case '-':
                ans -= cur;
                break;
            case '*':
                ans *= cur;
                break;
            case '/':
                ans /= cur;
                break;
            default:
                break;
        }
    }
    printf("%f", ans);
    return 0;
}