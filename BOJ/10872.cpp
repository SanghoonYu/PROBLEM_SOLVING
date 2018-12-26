#include <stdio.h>

using namespace std;

int main()
{
    int N;
    int CNT_2 = 0;
    int CNT_5 = 0;
    int ANS = 0;
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int tmp = i;
        while (tmp % 5 == 0)
        {
            tmp = tmp / 5;
            CNT_5++;
        }
        while (tmp % 2 == 0)
        {
            tmp = tmp / 2;
            CNT_2++;
        }
    }
    
    ANS = (CNT_5 < CNT_2) ? CNT_5 : CNT_2;
    printf("%d", ANS);

    return 0;
}