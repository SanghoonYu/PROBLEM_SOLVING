#include <iostream>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

int DP[100001] = {0};

int main()
{
    int N, C;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    DP[0] = 0;
    for (int i = 1; i <= N; i++) {
        //scanf("%d", &DP[i]);
        DP[i] = i;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j * j <= i; j++)
            DP[i] = MIN(DP[i], DP[i - j * j] + 1);
    }
    
    printf("%d\n", DP[N]);

    return 0;
}
