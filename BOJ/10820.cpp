#include <iostream>

int main()
{
    char word[102];
    int cnt[4] = {0}; //Lower, Upper, #, W.S
    char c = 'a';

    freopen("input.txt", "r", stdin);

    while (fgets(word, 102, stdin) != NULL)
    {
        int x = 0;
        while (word[x] != '\0')
        {
            c = word[x];

            if (c >= 'a' && c <= 'z')
                cnt[0]++;
            else if (c >= 'A' && c <= 'Z')
                cnt[1]++;
            else if (c >= '0' && c <= '9')
                cnt[2]++;
            else if (c == ' ')
                cnt[3]++;
            
            x++;
        }

        printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
        for (int i = 0; i < 4; i++)
            cnt[i] = 0;

    }

    return 0;
}