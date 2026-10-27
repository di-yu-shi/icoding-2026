#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d/%d+%d/%d", &a, &b, &c, &d);
    printf("%d/%d", a * d + c * b, b * d);
    return 0;
}