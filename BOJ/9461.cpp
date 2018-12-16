#include <iostream>

using namespace std;

long long DP[101] = {0};

//F[n] = F[n-2] + F[n-3]

int main()
{
    int T, N;

    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    DP[1] = DP[2] = DP[3] = 1;

    for (int i = 0 ; i < T; i++) {
        scanf("%d", &N);
        if (DP[N] == 0) {
            for (int j = 4; j <= N; j++) {
                DP[j] = DP[j - 2] + DP[j - 3];
            }
        }
        printf("%lld\n", DP[N]);
    }        
    return 0;
}
