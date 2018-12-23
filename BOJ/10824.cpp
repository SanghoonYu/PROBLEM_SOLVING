#include <stdio.h>

using namespace std;

long long get_tenth(long long x)
{
    long long tenth = 1000000;
    while ((x / tenth) == 0)
    {
        tenth = tenth / 10;
    }

    return tenth * 10;
}

int main()
{
    long long A, B, C, D;
    long long SUM1 = 0, SUM2 = 0, SUM;

    freopen("input.txt", "r", stdin);
    
    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
    SUM1 = A * get_tenth(B) + B;
    SUM2 = C * get_tenth(D) + D;
    SUM = SUM1 + SUM2;

    printf("%lld", SUM);

    return 0;
}