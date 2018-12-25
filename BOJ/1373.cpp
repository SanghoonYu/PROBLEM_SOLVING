#include <stdio.h>

using namespace std;

int main()
{
    char N[1000002];
    char ANS[333334];
    int len = 0;
    int pos = 0;
    int div = 0;
    int tmp = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", N);
    while (N[len] != '\0')
    {
        len++;
    }

    div = (len - 1) % 3; // when i hits div, then move to next point

    for (int i = 0; i < len; i++)
    {
        tmp = (tmp * 2) + (N[i] - '0');

        if ((i % 3) == div) {
            ANS[pos++] = tmp + '0';
            tmp = 0;
        }
    }
    ANS[pos] = '\0';

    printf("%s", ANS);

    return 0;
}