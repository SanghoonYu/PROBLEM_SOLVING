#include <iostream>

using namespace std;

int N, M;
int EDGE[1001][1001] = {0}; // {from / to};
int VISITS[1001] = {0};

void DFS(int S)
{
    if (VISITS[S] == 1)
        return;

    VISITS[S] = 1;

    for (int i = 1; i <= N; i++)
    {
        if (EDGE[S][i] == 1)
            DFS(i);
    }
}


int main()
{
    int C = 0;
    int tmp1, tmp2;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        EDGE[tmp1][tmp2] = 1;
        EDGE[tmp2][tmp1] = 1;
    }

    for (int i = 0; i <= N; i++)
        VISITS[i] = 0;

    for (int i = 1; i <= N; i++)
    {
        if (VISITS[i] == 0)
        {
            DFS(i);
            C++;
        }
    }
    printf("%d", C);


    return 0;
}