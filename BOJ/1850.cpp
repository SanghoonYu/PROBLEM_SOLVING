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
    long long A, B;
    long long answer;
    long long GCD;

    freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &A, &B);

    GCD = (A > B) ? get_gcd(A, B) : get_gcd(B ,A);
    while (GCD-- > 0) {
        printf("1");
    }

    return 0;
}