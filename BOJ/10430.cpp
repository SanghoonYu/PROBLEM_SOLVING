#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    int X;

    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &A, &B, &C);

    X = (A + B) % C;
    printf("%d\n", X);
    X = ((A % C) + (B % C)) % C;
    printf("%d\n", X);
    X = (A * B) % C;
    printf("%d\n", X);
    X = ((A % C) * (B % C)) % C;
    printf("%d\n", X);

    return 0;
}