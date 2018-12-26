#include <iostream>

using namespace std;
int get_sqrt(int x) 
{
    int a = x / 2;
    if (x == 1)
        return 1;
    
    for (int i = 0; i < 10; i++)
        a = (a + (x / a)) / 2;
    
    return a;
}

int main()
{
    int M, N;
    int MARKING = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &M, &N);

    for (int tmp = M; tmp <= N; tmp++)
    {
        MARKING = 0;
        int root_tmp = get_sqrt(tmp);
        if (tmp == 1) 
            MARKING = 1;
        for (int i = 2; i <= root_tmp; i++)
        {
            if (tmp % i == 0)
            {
                MARKING = 1;
                break;
            }
        }
        if (MARKING == 0)
            printf("%d\n", tmp);
    }

    return 0;
}