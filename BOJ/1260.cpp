#include <iostream>

using namespace std;

int N;
int EDGE[1001][1001] = {0}; // {from / to};
int VISITS[1001] = {0};

int Q[1020];
int Q_HEAD = 0;
int Q_TAIL = 0;

int empty_qu()
{
    if (Q_HEAD == Q_TAIL)
        return 1;
    return 0;
}

void push_qu(int in)
{
    Q[Q_TAIL++] = in;
}

int pop_qu()
{
    return Q[Q_HEAD++];
}

void DFS(int S)
{
    if (VISITS[S] == 1)
        return;

    VISITS[S] = 1;

    printf("%d ", S);
    for (int i = 1; i <= N; i++)
    {
        if (EDGE[S][i] == 1)
            DFS(i);
    }
}

void BFS(int S)
{
    VISITS[S] = 1;

    push_qu(S);

    while (!empty_qu())
    {
        int x = pop_qu();
        printf("%d ", x);
        for (int i = 1; i <= N; i++)
        {
            if (!VISITS[i] && EDGE[x][i])
            {
                push_qu(i);
                VISITS[i] = 1;
            }
        }
    }
}

int main()
{
    int M, V;
    int tmp1, tmp2;

    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        EDGE[tmp1][tmp2] = 1;
        EDGE[tmp2][tmp1] = 1;
    }

    for (int i = 0; i <= N; i++)
        VISITS[i] = 0;

    DFS(V);
    printf("\n");

    for (int i = 0; i <= N; i++)
        VISITS[i] = 0;

    BFS(V);

    return 0;
}