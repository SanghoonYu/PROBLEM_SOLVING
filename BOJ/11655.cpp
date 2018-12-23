#include <stdio.h>

char ROT13(char x)
{
    if (x >= 'a' && x <= 'z') {
        x -= 13;
        if (x < 'a') {
            x += 26;
        }
    } 
    else if (x >= 'A' && x <= 'Z') 
    {
        x -= 13;
        if (x < 'A')
        {
            x += 26;
        }
    }
    return x;
}

int main()
{
    char word[102];
    int len = 0;
    int i = 0;

    freopen("input.txt", "r", stdin);

    fgets(word, 102, stdin);

    while (word[i] != '\0')
    {
        word[i] = ROT13(word[i]);
        i++;
    }
    
    printf("%s\n", word);
    
    return 0;
}