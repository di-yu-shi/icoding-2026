#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; ; i += 2)
    {
        if (i * i > n)
        {
            break;
        }
        printf("%d\n", i * i);
    }
    return 0;
}