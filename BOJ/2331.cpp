#include <iostream>
#define MAX(A, B) ((A > B) ? A : B)
using namespace std;

int CHECK[1000001];

int pow(int num, int p)
{
    int ret = 1;
    for (int i = 0; i < p; i++)
        ret *= num;
    return ret;
}

int next_num(int num, int P)
{
    int tmp = num;
    int sum = 0;
    while (tmp > 0)
    {
        int a;
        a = tmp % 10;
        tmp = tmp / 10;
        sum += pow(a, P);
    }
    return sum;
}

int main()
{
    int A, P;
    int N = 1000000;
    int max = 0;
    int cnt = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &A, &P);

    int i = A;
    max = A;
    while (CHECK[i] < 2) {
        CHECK[i]++;
        i = next_num(i, P);
        max = MAX(max, i);
    }
    for (int i = 0; i <= max; i++)
    {
        if (CHECK[i] == 1) {
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}