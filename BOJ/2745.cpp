#include <iostream>

using namespace std;

long long convert_digit(char c)
{
    long long ret;
    
    if (c >= 'A' && c <= 'Z')
        ret = 10 + (c - 'A');
    else
        ret = c - '0';

    return ret;
}

int main()
{
    char N[50];
    long long B;
    long long ANS = 0;
    int len = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", N);
    scanf("%lld", &B);

    while (N[len] != '\0')
        len++;

    for (int i = 0; i < len; ++i)
    {
        ANS = (ANS * B) + convert_digit(N[i]);
    }

    printf("%lld", ANS);
    return 0;
}