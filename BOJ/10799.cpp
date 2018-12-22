#include <iostream>

#define SYM_LASER 'C'

using namespace std;

char *st_ptr;
char STACK[100001];

void stack_push(char c)
{
    *st_ptr = c;
    st_ptr++;
}

char stack_pop()
{
    if (st_ptr > STACK)
    {
        char c = *(st_ptr - 1);
        st_ptr--;
        return c;
    }
    return '\0';
}

bool stack_empty()
{
    if (st_ptr == STACK)
        return true;
    return false;
}

char stack_top()
{
    return *(st_ptr - 1);
}

void stack_clear()
{
    st_ptr = STACK;
}

int main()
{
    char ORG_STR[100001];
    int cnt_pipe = 0;
    int lay_pipe = 0;
    int i = 0;

    freopen("input.txt", "r", stdin);

    scanf("%s", ORG_STR);

    st_ptr = STACK;

    while (ORG_STR[i] != '\0' && ORG_STR[i] != '\n')
    {
        char c = ORG_STR[i];
        switch (c)
        {
        case '(':
            stack_push(c);
            break;
        case ')':
            if (stack_top() == '(')
            {
                char x = stack_pop();
                stack_push(SYM_LASER);
            }
            else
            {
                stack_push(c);
            }
            break;
        }
        i++;
    }

    while (!stack_empty())
    {
        char c = stack_pop();
        switch (c)
        {
        case ')':
            lay_pipe++;
            break;
        case '(':
            lay_pipe--;
            cnt_pipe++;
            break;
        case SYM_LASER:
            cnt_pipe += (lay_pipe);
            break;
        }
    }

    printf("%d", cnt_pipe);

    return 0;
}
