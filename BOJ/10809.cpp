#include <iostream>

int main()
{
    char word[102];
    int pos[26] = {-1};
    char c;
    int i = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", &word);

    for (int i = 0; i < 26; i++) {
        pos[i] = -1;
    }
    while (word[i] != '\0')
    {
        c = word[i];
        if (pos[c - 'a'] == -1)
            pos[c - 'a'] = i;
        i++;
    }

    for (int i = 0; i < 26; i++)
        printf("%d ", pos[i]);

    return 0;
}