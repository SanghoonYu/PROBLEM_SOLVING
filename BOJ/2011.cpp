#include <iostream>

#define DIV 1000000

using namespace std;

int DP[5001] = {1, 1};
char ORG[5001];
//F(n) = F(n-1) ... [If last digit > 0]
//     + F(n-2) ... [If last 2 digits 10 ~ 26]
int main()
{
    int cnt = 0;
    freopen("input.txt", "r", stdin);

    scanf("%s", ORG);
    while (ORG[cnt] != '\0')
        cnt++;

    for (int i = 2; i <= cnt; i++) {
        if (ORG[i - 1] > '0')
            DP[i] = (DP[i - 1] % DIV);
        
        int sum = (ORG[i - 2] - '0') * 10 + (ORG[i - 1] - '0');
        if (sum >= 10 && sum <= 26)
            DP[i] += (DP[i - 2] % DIV);
    }

    if (ORG[0] == '0')
        printf("0");
    else
        printf("%d", DP[cnt] % DIV);

    return 0;
}

