#include <iostream>

#define MAX_N 1000

using namespace std;

int N;
int EDGE[MAX_N + 1] = {0};
int VISITS[MAX_N + 1] = {0};

void DFS(int S)
{
    if (VISITS[S] > 0)
        return;

    VISITS[S] = 1;

    int next = EDGE[S];
    DFS(next);
}

int main()
{
    int T;
    int tmp1, tmp2;
    int C;

    freopen("input.txt", "r", stdin);

    scanf("%d", &T);
    while (T-- > 0)
    {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &EDGE[i]);
            VISITS[i] = 0;
        }
        C = 0;

        for (int i = 1; i <= N; i++)
        {
            if (VISITS[i] == 0)
            {
                DFS(i);
                C++;
            }
        }
        printf("%d\n", C);
    }

    return 0;
}