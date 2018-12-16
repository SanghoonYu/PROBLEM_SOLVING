#include <iostream>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

int DP[30] = {0};

//F[n] = F[n-2] * 3 + (F(N-4 ... 0) * 2)

int main()
{
    int N;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    DP[0] = 1;
    DP[2] = 3;
    if (N % 2 != 0) {
        DP[N] = 0;
    } else {

        for (int i = 4; i <= N; i = i + 2) {
            DP[i] = DP [i - 2] * 3;
            for (int j = i; j >= 4; j = j - 2) {
                DP[i] += DP[i - j] * 2;
            }
        }
    }
    printf("%d\n", DP[N]);
    return 0;
}
