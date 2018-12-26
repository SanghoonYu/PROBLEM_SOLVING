#include <iostream>

#define MAX_N 1000000

using namespace std;

int PRIME_FILTER[MAX_N + 1] = {0};

void build_filter()
{
    int i = 2;
    PRIME_FILTER[1] = 1;

    for (i = 2; i <= MAX_N; i++)
    {
        if (!PRIME_FILTER[i])
        {
            for (int j = i + i; j <= MAX_N; j = j + i)
            {
                PRIME_FILTER[j] = 1;
            }
        }
    }
}

int main()
{
    int N = 1;
    int A, B;
    int FOUND = 0;

    freopen("input.txt", "r", stdin);

    build_filter();

    while (1)
    {
        scanf("%d", &N);
        
        if (N == 0) break;

        FOUND = 0;

        //PRIME_FILTER == 0: --> PRIME NUMBER
        for (A = 3; A < ((N / 2) + 1); A++)
        {
            B = N - A;
            if (!PRIME_FILTER[A] && !PRIME_FILTER[B]) {
                FOUND = 1;       
                break;
            }
        }
        if (FOUND) {
            printf("%d = %d + %d\n", N, A, B);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }

    } 

    return 0;
}