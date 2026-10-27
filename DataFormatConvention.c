#include <stdio.h>

int main()
{
    int d, m, y;
    scanf("%d/%d/%d", &m, &d, &y);
    printf("You entered the date %04d%02d%02d", y, m, d);
}