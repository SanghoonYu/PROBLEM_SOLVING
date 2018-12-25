#include <iostream>

using namespace std;

char convert_digit(long long x)
{
    char c;
    if (x < 10)
        c = '0' + x;
    else
        c = 'A' + (x - 10);

    return c;
}

int main()
{
    long long N, B;
    char ANS[20];
    long long tmp;
    int len = 0;

    freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &N, &B);

    
    while (N != 0) {
        tmp = N % B;
        ANS[len++] = convert_digit(tmp);
        N = N / B;
    }

    while (len-- > 0)
        printf("%c", ANS[len]);

    return 0;
}