#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))

bool cmp(char *a, char *b)
{
    for (int i = 0; i < MIN(strlen(a), strlen(b)); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return strlen(a) > strlen(b);
}

int main()
{
    int cnt = 0, smallest = 0, biggest = 0;
    char c[10005][21];
    while (1)
    {
        fgets(c[cnt], sizeof(c[cnt]), stdin);
        c[cnt][strcspn(c[cnt], "\r\n")] = '\0';
        if (!cmp(c[cnt], c[smallest]))
        {
            smallest = cnt;
        }
        if (cmp(c[cnt], c[biggest]))
        {
            biggest = cnt;
        }
        if (strlen(c[cnt]) == 4)
        {
            break;
        }
        cnt++;
    }
    printf("Smallest word: %s\nLargest word: %s", c[smallest], c[biggest]);
    return 0;
}