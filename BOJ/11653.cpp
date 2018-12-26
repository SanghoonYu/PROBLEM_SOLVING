#include <stdio.h>

using namespace std;

int main()
{
    int N;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            printf("%d\n", i);
            N = N / i;
        }
    }

    return 0;
}