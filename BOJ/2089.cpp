#include <stdio.h>

#define DIVIDER -2

using namespace std;

int main()
{
    int N;
    char tmp[500];
    char ANS[500];
    int pos = 0;
    int carry = 0;

    int A, B;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    if (N == 0)
    {
        printf("0");
    }
    else
    {
        while (N != 0)
        {
            A = N / DIVIDER;
            B = N % DIVIDER;
            if (B != 0)
            {
                carry = 1;
                tmp[pos++] = '1';
            }
            else
            {
                carry = 0;
                tmp[pos++] = '0';
            }

            if (A >= 0 && B == -1)
            {
                A = A + carry;
            }

            N = A;
            carry = 0;
        }
        tmp[pos] = '\0';

        // Reverse
        for (int i = 0; i < pos; i++)
        {
            ANS[i] = tmp[pos - i - 1];
        }
        ANS[pos] = '\0';
        printf("%s", ANS);
    }

    return 0;
}