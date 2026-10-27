#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf("$20 bills: %d\n", a / 20);
    a %= 20;
    printf("$10 bills: %d\n", a / 10);
    a %= 10;
    printf("$5 bills: %d\n", a / 5);
    a %= 5;
    printf("$1 bills: %d\n", a);
    return 0;
}