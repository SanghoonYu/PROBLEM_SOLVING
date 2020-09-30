#include <iostream>

using namespace std;

int E[100001] = {0}; // Data for next node.
int V[100001];       // # of IN edge [Out Edge == 1 in this PS]
bool VISITED[100001];

int main()
{
    int T;
    int N;
    int CNT;

    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while (T-- > 0)
    {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
        {
            VISITED[i] = false;
            V[i] = 0;
        }
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &E[i]);
            V[E[i]]++;
        }

        CNT = 0;
        for (int i = 1; i <= N; i++)
        {
            int tmp = i;
            // while the node was not visited & has any entering edge.
            while (!VISITED[tmp] && !V[tmp])
            {
                CNT++;
                VISITED[tmp] = true;
                int next = E[tmp];
                V[next]--; // Eliminate out direction edge.
                tmp = E[tmp];
            }
        }

        printf("%d\n", CNT);
    }

    return 0;
}