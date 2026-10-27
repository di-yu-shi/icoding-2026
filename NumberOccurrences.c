#include <stdio.h>
#include <string.h>

int main()
{
    char a[105];
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\r\n")] = '\0';
    for (int i = 0; i < strlen(a); i++)
    {
        cnt[a[i] - '0']++;
    }
    printf("Digit: 0 1 2 3 4 5 6 7 8 9\nOccurrences: ");
    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", cnt[i]);
    }
    return 0;
}