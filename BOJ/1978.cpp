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
    int N;
    int num[1002] = {0};
    int i = 0;
    int C = 0;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);
    C = N;

    while (N-- > 0)
    {
        int tmp;
        int root_tmp;
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            C--;
            continue;
        }

        root_tmp = get_sqrt(tmp);
        for (int i = 2; i <= root_tmp; i++)
        {
            if (tmp % i == 0)
            {
                C--;
                break;
            }
        }
    }
    printf("%d", C);

    return 0;
}