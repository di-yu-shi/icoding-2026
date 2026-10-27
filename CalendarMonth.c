#include <stdio.h>

int main()
{
    int cnt, st;
    scanf("%d\n%d", &cnt, &st);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d ", i);
        if (i % 7 == (8 - st) % 7)
        {
            putchar('\n');
        }
    }
    return 0;
}