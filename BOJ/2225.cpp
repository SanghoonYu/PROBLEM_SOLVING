#include <iostream>

#define DIV 1000000000

using namespace std;

int DP[201][201] = {0};

//F(n,k) = F(n-1,k) + F(n,k-1)

int main()
{
    int N, K;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= K; i++) DP[1][i] = i;
    for (int i = 1; i <= N; i++) DP[i][1] = 1;

    for (int i = 2; i <= K; i++) {
        for (int j = 2; j <= N; j++) {
            DP[j][i] = ((DP[j - 1][i] % DIV) + (DP[j][i - 1] % DIV)) %DIV;
        }
    }

    printf("%d\n", DP[N][K]);


    return 0;
}
