#include <iostream>

using namespace std;

int get_gcd(int A, int B)
{
    int N = A;
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
    int A, B;
    int tmp = 1;
    int GCD = 0, LCM = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &A, &B);

    GCD = (A > B) ? get_gcd(A, B) : get_gcd(B, A);
    LCM = (A / GCD) * B;

    printf("%d\n", GCD);
    printf("%d\n", LCM);

    return 0;
}