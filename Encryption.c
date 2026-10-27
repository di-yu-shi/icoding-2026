#include <stdio.h>
#include <string.h>

int main()
{
    int shift;
    char s[105];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\r\n")] = '\0';
    scanf("%d", &shift);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] - 'A' + shift) % 26;
        }
    }
    printf("%s", s);
    return 0;
}