#include <stdio.h>

int main()
{
    int spd;
    scanf("%d", &spd);
    if (spd <= 0)
    {
        printf("Calm");
    }
    else if (spd <= 3)
    {
        printf("Light air");
    }
    else if (spd <= 27)
    {
        printf("Breeze");
    }
    else if (spd <= 47)
    {
        printf("Gale");
    }
    else if (spd <= 63)
    {
        printf("Storm");
    }
    else
    {
        printf("Hurricane");
    }
    return 0;
}