#include <iostream>

#define C_PUSH  1
#define C_POP   2
#define C_SIZE  3
#define C_EMPTY 4
#define C_TOP   5

using namespace std;

int parse_cmd(char cmd[])
{
    switch (cmd[0])
    {
    case 'p':
        if (cmd[1] == 'u')
            return C_PUSH;
        else
            return C_POP;
        break;
    case 's':
        return C_SIZE;
        break;
    case 'e':
        return C_EMPTY;
        break;
    case 't':
        return C_TOP;
        break;
    default:
        return C_TOP;
    }
}

int main()
{
    int N;
    int STACK[10001];
    char CMD[20];
    int tmp;
    int *st_ptr = STACK;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    while (N-- > 0) {
        scanf("%s", CMD);
        switch (parse_cmd(CMD))
        {
        case C_PUSH:
            scanf("%d", &tmp);
            *st_ptr = tmp;
            st_ptr++;
            break;
        case C_POP:
            if (st_ptr == STACK) {
                tmp = -1;
            } else {
                st_ptr--;
                tmp = *st_ptr;
            }
            printf("%d\n", tmp);
            break;
        case C_TOP:
            if (st_ptr == STACK) {
                tmp = -1;
            } else {
                tmp = *(st_ptr - 1);
            }
            printf("%d\n", tmp);
            break;
        case C_SIZE:
            tmp = st_ptr - STACK;
            printf("%d\n", tmp);
            break;
        case C_EMPTY:
            tmp = (st_ptr == STACK) ? 1 : 0;
            printf("%d\n",tmp);
            break;
        }
    }

    return 0;
}
