#include <iostream>

using namespace std;

int main()
{
    int A, B;
    int N;
    int in;
    int to[30];
    int tmp = 0;
    int tmp2 = 0;
    int pos = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &A, &B);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &in);
        tmp = tmp * A + in;
    }

    while (tmp > 0)
    {
        to[pos++] = tmp % B;
        tmp = tmp / B;
    }

    for (int i = pos - 1; i >= 0; i--)
        printf("%d ", to[i]);
    return 0;
}