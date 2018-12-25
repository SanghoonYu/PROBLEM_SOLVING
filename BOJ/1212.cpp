#include <stdio.h>

using namespace std;

int main()
{
    char N[333335];
    char ANS[1000005];
    int pos = 0;
    int x = 0;
    int tenth = 0;
    int tmp = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", N);

    tmp = N[x++] - '0';

    //Exceptional processing of initial digit.
    switch (tmp)
    {
    case 0:
        ANS[pos++] = '0';
        break;
    case 1:
        ANS[pos++] = '1';
        break;
    case 2:
        ANS[pos++] = '1';
        ANS[pos++] = '0';
        break;
    case 3:
        ANS[pos++] = '1';
        ANS[pos++] = '1';
        break;
    case 4:
        ANS[pos++] = '1';
        ANS[pos++] = '0';
        ANS[pos++] = '0';
        break;
    case 5:
        ANS[pos++] = '1';
        ANS[pos++] = '0';
        ANS[pos++] = '1';
        break;
    case 6:
        ANS[pos++] = '1';
        ANS[pos++] = '1';
        ANS[pos++] = '0';
        break;
    case 7:
        ANS[pos++] = '1';
        ANS[pos++] = '1';
        ANS[pos++] = '1';
        break;
    }

    while (N[x] != '\0')
    {
        int tmp = N[x] - '0';
        switch (tmp)
        {
        case 0:
            ANS[pos++] = '0';
            ANS[pos++] = '0';
            ANS[pos++] = '0';
            break;
        case 1:
            ANS[pos++] = '0';
            ANS[pos++] = '0';
            ANS[pos++] = '1';
            break;
        case 2:
            ANS[pos++] = '0';
            ANS[pos++] = '1';
            ANS[pos++] = '0';
            break;
        case 3:
            ANS[pos++] = '0';
            ANS[pos++] = '1';
            ANS[pos++] = '1';
            break;
        case 4:
            ANS[pos++] = '1';
            ANS[pos++] = '0';
            ANS[pos++] = '0';
            break;
        case 5:
            ANS[pos++] = '1';
            ANS[pos++] = '0';
            ANS[pos++] = '1';
            break;
        case 6:
            ANS[pos++] = '1';
            ANS[pos++] = '1';
            ANS[pos++] = '0';
            break;
        case 7:
            ANS[pos++] = '1';
            ANS[pos++] = '1';
            ANS[pos++] = '1';
            break;
        }
        x++;
    }
    ANS[pos] = '\0';

    printf("%s", ANS);

    return 0;
}