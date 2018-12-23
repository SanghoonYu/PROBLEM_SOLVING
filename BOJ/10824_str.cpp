#include <stdio.h>

using namespace std;

int get_len(char A[])
{
    int len = 0;
    while (A[len] != '\0')
    {
        len++;
    }
    return len;
}
void concat(char A[], char B[], char *C)
{
    int x = 0;
    for (int i = 0; i < get_len(A); i++)
    {
        C[x++] = A[i];
    }
    for (int i = 0; i < get_len(B); i++)
    {
        C[x++] = B[i];
    }
    C[x] = '\0';
}

void sum_str(char A[], char B[], char *OUT)
{
    char carry = 0;
    int x = get_len(A);
    int y = get_len(B);
    char C[30];
    int idx = 0;

    while (x-- > 0 && y-- > 0)
    {
        char sum = (A[x] - '0') + (B[y] - '0') + carry;
        if (sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        C[idx++] = (sum % 10) + '0';
    }

    while (x-- > 0)
    {
        char sum = (A[x] - '0') + carry;
        if (sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        C[idx++] = (sum % 10) + '0';
    }
    while (y-- > 0)
    {
        char sum = (B[y] - '0') + carry;
        if (sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        C[idx++] = (sum % 10) + '0';
    }
    
    if (carry > 0) {
        C[idx++] = '1';
    }
    C[idx] = '\0';

    for (int i = 0; i < get_len(C); i++)
    {
        OUT[i] = C[idx - i - 1];
    }
    OUT[idx] = '\0';
}

int main()
{
    char A[10];
    char B[10];
    char C[10];
    char D[10];
    char SUM1[20];
    char SUM2[20];
    char SUM[36];

    freopen("input.txt", "r", stdin);

    scanf("%s %s %s %s", A, B, C, D);

    concat(A, B, SUM1);
    concat(C, D, SUM2);
    
    sum_str(SUM1, SUM2, SUM);
    
    printf("%s + %s\n", SUM1, SUM2);
    printf("%s\n", SUM);

    return 0;
}