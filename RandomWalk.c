#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool chk(char map[][10], int *movX, int *movY, int curX, int curY, int op)
{
    if (curX + movX[op] < 0 || curX + movX[op] > 9 || curY + movY[op] < 0 || curY + movY[op] > 9)
    {
        return false;
    }
    if (map[curX + movX[op]][curY + movY[op]] != '.')
    {
        return false;
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));
    char map[10][10];
    int movX[4] = {-1, 1, 0, 0};
    int movY[4] = {0, 0, -1, 1};
    int curX = 0, curY = 0;
    memset(map, '.', sizeof(map));
    for (int i = 0; i < 26; i++)
    {
        map[curX][curY] = 'A' + i;
        if (!chk(map, movX, movY, curX, curY, 0) && !chk(map, movX, movY, curX, curY, 1) && !chk(map, movX, movY, curX, curY, 2) && !chk(map, movX, movY, curX, curY, 3))
        {
            break;
        }
        int op = rand() % 4;
        while (!chk(map, movX, movY, curX, curY, op))
        {
            op = (op + 1) % 4;
        }
        curX += movX[op];
        curY += movY[op];
    }
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
    return 0;
}