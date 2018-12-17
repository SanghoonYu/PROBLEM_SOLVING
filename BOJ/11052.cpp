#include <iostream>

#define MAX(A, B) ((A > B) ? A : B)

using namespace std;

int DP[1001] = {0};
int P[1001] = {0};
// F(n) = max(F(n-1)+P1, F(n-2)+P2, ... ,F(1)+Pn-1)

int main()
{
    int N;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &P[i]);

    DP[1] = P[1];
    for (int i = 2; i <= N; i++) {
        int max = P[i];
        for (int j = 1; j < i; j++) {
            max = MAX(DP[i - j] + P[j], max);
        }
        DP[i] = max;
    }
    printf("%d\n", DP[N]);
    return 0;
}

