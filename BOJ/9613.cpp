#include <iostream>

using namespace std;

long long get_gcd(long long A, long long B)
{
    long long N = A;

    while (1) {
        N = A % B;

        if (N == 0)
            break;
        
        A = B;
        B = N;
    }
    return B;
}

int main()
{
    int T, N;
    long long num[100];
    long long GCD = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while (T-- > 0)
    {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
            scanf("%lld", &num[i]);

        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                GCD += (num[i] > num[j]) ? get_gcd(num[i], num[j]) : get_gcd(num[j], num[i]);
            }
        }
        printf("%lld\n", GCD);
        GCD = 0;
    }

    return 0;
}