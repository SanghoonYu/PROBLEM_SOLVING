#include <stdio.h>

using namespace std;

int ARR[10001] = {0};

int main()
{
    int N;
    int X;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &X);
        ARR[X]++;
    }

    for (int i = 1; i <= 10000; ++i) {
        for (int j = 0; j < ARR[i]; j++)
            printf("%d\n", i);
    }

    return 0;
}
