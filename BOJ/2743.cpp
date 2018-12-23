#include <stdio.h>

int main()
{
    char word[102];
    int len = 0;
    int i = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", word);

    while (word[i++] != '\0')
    {
        len++;
    }
    
    printf("%d\n", len);
    
    return 0;
}