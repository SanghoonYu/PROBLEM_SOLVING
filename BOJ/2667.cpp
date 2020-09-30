#include <iostream>

using namespace std;

int N;
int MAP[25][25] = {0};
bool VISITED[25][25] = {false};
int CNT = 0;
int MAX = 0;
int MAX_C[((25 * 25) / 2) + 1] = {0};

void DPS(int x, int y)
{
    if (x >= N || y >= N || x < 0 || y < 0)
        return;

    if (VISITED[x][y] || (MAP[x][y] == 0))
        return;

    VISITED[x][y] = true;
    MAX++;

    // Right / Down / Left / Up
    DPS(x, y + 1);
    DPS(x + 1, y);
    DPS(x, y - 1);
    DPS(x - 1, y);
}

void PUSH_COUNT(int in)
{
    int i = 0;

    while (MAX_C[i] <= in && i < CNT)
        i++;

    int j = CNT;
    while (j >= i)
    {
        MAX_C[j + 1] = MAX_C[j];
        j--;
    }
    MAX_C[i] = in;
}

int main()
{
    char tmp[30];

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", tmp);
        for (int j = 0; j < N; j++)
        {
            MAP[i][j] = (tmp[j] == '1') ? 1 : 0;
            VISITED[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (VISITED[i][j] == false && MAP[i][j])
            {
                MAX = 0;
                DPS(i, j);
                PUSH_COUNT(MAX);
                CNT++;
            }
        }
    }

    printf("%d\n", CNT);
    for (int i = 0; i < CNT; i++)
        printf("%d\n", MAX_C[i]);

    return 0;
}