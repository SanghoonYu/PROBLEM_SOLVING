#include <iostream>

int main()
{
    char word[102];
    int cnt[26] = {0};
    char c;
    int i = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", &word);

    while (word[i] != '\0')
    {
        c = word[i++];
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        printf("%d ", cnt[i]);

    return 0;
}