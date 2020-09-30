/********************************************************************
 * Vector or 동적 메모리 할당 없이는 Time out or Memeory over로 풀이불가 (?)
********************************************************************/
#include <iostream>

#define RED 1
#define BLACK 2

using namespace std;

int N, M;
//bool EDGE[20001][20001]; // {from / to};
int EDGE[200001][2];
int VISITS[20001] = {0};
bool Biparties = true;

void DFS(int S, int color)
{
    if (VISITS[S] > 0)
        return;

    VISITS[S] = color;

    for (int i = 0; i < M; i++)
    {
        if (EDGE[i][0] == S)
        {
            int next = EDGE[i][1];
            if (VISITS[next] != 0 && VISITS[S] == VISITS[next])
            {
                Biparties = false;
                return;
            }
            DFS(next, 3 - color);
        }
    }
}

int main()
{
    int T;
    int tmp1, tmp2;

    freopen("input.txt", "r", stdin);

    scanf("%d", &T);
    while (T-- > 0)
    {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < M; i++)
        {
            EDGE[i][0] = 0;
            EDGE[i][1] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &tmp1, &tmp2);
            EDGE[i][0] = (tmp1 < tmp2) ? tmp1 : tmp2;
            EDGE[i][1] = (tmp1 >= tmp2) ? tmp1 : tmp2;
        }
        for (int i = 0; i <= N; i++)
            VISITS[i] = 0;

        Biparties = true;

        for (int i = 1; i <= N; i++)
        {
            if (VISITS[i] == 0)
            {
                DFS(i, RED);
            }
        }
        if (Biparties)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}