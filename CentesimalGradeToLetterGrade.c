#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    if (score >= 90 && score <= 100)
    {
        printf("Letter grade: A");
    }
    else if (score >= 80 && score < 90)
    {
        printf("Letter grade: B");
    }
    else if (score >= 70 && score < 80)
    {
        printf("Letter grade: C");
    }
    else if (score >= 60 && score < 70)
    {
        printf("Letter grade: D");
    }
    else if (score >= 0 && score < 60)
    {
        printf("Letter grade: F");
    }
    else
    {
        printf("Error, grade must be between 0 and 100.");
    }
    return 0;
}