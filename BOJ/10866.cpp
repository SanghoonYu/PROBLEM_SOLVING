#include <iostream>

#define Q_SIZE 10000

#define INC_IDX(A) ((A + 1) % Q_SIZE)
#define DEC_IDX(A) ((A + Q_SIZE - 1) % Q_SIZE)

#define C_PUSH_FRONT    1
#define C_PUSH_BACK     2
#define C_POP_FRONT     3
#define C_POP_BACK      4
#define C_SIZE          5
#define C_EMPTY         6
#define C_FRONT         7
#define C_BACK          8

using namespace std;

int parse_cmd(char cmd[]);
void qu_push_back(int in);
void qu_push_front(int in);
int qu_pop_back();
int qu_pop_front();
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
            case C_PUSH_BACK:
                scanf("%d", &cmd_arg);
                qu_push_back(cmd_arg);
                continue;
            case C_PUSH_FRONT:
                scanf("%d", &cmd_arg);
                qu_push_front(cmd_arg);
                continue;
            case C_POP_BACK:
                tmp = qu_pop_back();
                break;
            case C_POP_FRONT:
                tmp = qu_pop_front();
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
            if (cmd[5] == 'b')
                return C_PUSH_BACK;
            else if (cmd[5] == 'f')
                return C_PUSH_FRONT;
        }
        else if (cmd[1] == 'o')
        {
            if (cmd[4] == 'b')
                return C_POP_BACK;
            else if (cmd[4] == 'f')
                return C_POP_FRONT;
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

void qu_push_back(int in)
{
    DATA[idx_back] = in;
    idx_back = INC_IDX(idx_back);
}

void qu_push_front(int in)
{
    idx_front = DEC_IDX(idx_front);
    DATA[idx_front] = in;
}

int qu_pop_front()
{
    int x;
    if (qu_empty())
        return -1;
    x = DATA[idx_front];
    idx_front = INC_IDX(idx_front);
    return x;
}

int qu_pop_back()
{
    if (qu_empty())
        return -1;
    idx_back = DEC_IDX(idx_back);
    return DATA[idx_back];
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
    r_idx = DEC_IDX(idx_back);
    return DATA[r_idx];
}