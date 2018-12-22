#include <iostream>

#define Q_SIZE 10000

#define C_PUSH  1
#define C_POP   2
#define C_SIZE  3
#define C_EMPTY 4
#define C_FRONT 5
#define C_BACK  6

using namespace std;

int parse_cmd(char cmd[]);
void qu_push(int in);
int qu_pop();
int qu_size();
int qu_empty();
int qu_front();
int qu_back();

int DATA[Q_SIZE];
int idx_front = 0;
int idx_back = 0;

int main()
{
    int N;
    char cmd_in[20];
    int cmd_arg;
    int tmp;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    while (N-- > 0) {
        scanf("%s", cmd_in);
        
        switch (parse_cmd(cmd_in))
        {
            case C_PUSH:
                scanf("%d", &cmd_arg);
                qu_push(cmd_arg);
                continue;
            case C_POP:
                tmp = qu_pop();
                break;
            case C_SIZE:
                tmp = qu_size();
                break;
            case C_EMPTY:
                tmp = qu_empty();
                break;
            case C_FRONT:
                tmp = qu_front();
                break;
            case C_BACK:
                tmp = qu_back();
                break;
        }
        printf("%d\n", tmp);
    }

    return 0;
}

int parse_cmd(char cmd[])
{
    switch (cmd[0])
    {
    case 'p':
        if (cmd[1] == 'u')
        {
            return C_PUSH;
        }
        else if (cmd[1] == 'o')
        {
            return C_POP;
        }
        break;
    case 's':
        return C_SIZE;
        break;
    case 'e':
        return C_EMPTY;
        break;
    case 'f':
        return C_FRONT;
        break;
    case 'b':
        return C_BACK;
        break;
    }
}

void qu_push(int in)
{
    DATA[idx_back] = in;
    idx_back = (idx_back + 1) % Q_SIZE;
}

int qu_pop()
{
    int x;
    if (qu_empty())
        return -1;
    x = DATA[idx_front];
    idx_front = (idx_front + 1) % Q_SIZE;
    return x;
}

int qu_size()
{
    int size;
    size = idx_back - idx_front;
    if (size < 0)
        size += Q_SIZE;
    return size;
}

int qu_empty()
{
    if (idx_back == idx_front)
        return 1;
    return 0;
}

int qu_front()
{
    if (qu_empty())
    {
        return -1;
    }
    return DATA[idx_front];
}

int qu_back()
{
    int r_idx;
    if (qu_empty())
    {
        return -1;
    }
    r_idx = (idx_back + Q_SIZE - 1) % Q_SIZE;
    return DATA[r_idx];
}