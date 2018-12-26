#include <iostream>

using namespace std;

int main()
{
    long long N, M, R;
    long long CNT_2 = 0;
    long long CNT_5 = 0;
    long long ANS = 0;
    freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &N, &M);

    for (long long i = 5; i <= N; i = i * 5)
    {
        CNT_5 += N / i;
    }
    for (long long i = 2; i <= N; i = i * 2)
    {
        CNT_2 += N / i;
    }

    for (long long i = 5; i <= M; i = i * 5)
    {
        CNT_5 -= M / i;
    }

    for (long long i = 2; i <= M; i = i * 2)
    {
        CNT_2 -= M / i;
    }

    R = N - M;
    for (long long i = 5; i <= R; i = i * 5)
    {
        CNT_5 -= R / i;
    }

    for (long long i = 2; i <= R; i = i * 2)
    {
        CNT_2 -= R / i;
    }

    ANS = (CNT_5 < CNT_2) ? CNT_5 : CNT_2;
    printf("%lld", ANS);

    return 0;
}