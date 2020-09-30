#include <iostream>

#define MAX_H 50
#define MAX_W 50

using namespace std;

int W, H;
int MAP[MAX_H][MAX_W] = {0};
bool VISITED[MAX_H][MAX_W] = {false};
int CNT = 0;

void DPS(int x, int y)
{
    if (x >= W || y >= H || x < 0 || y < 0)
        return;

    if (VISITED[x][y] || (MAP[x][y] == 0))
        return;

    VISITED[x][y] = true;

    // Right, Right+Down, Down, Left+Down
    DPS(x, y + 1);
    DPS(x + 1, y + 1);
    DPS(x + 1, y);
    DPS(x + 1, y - 1);
}

//TODO: NEED TO FIX AXIS VARIABLES TO MATCH AXIS X AND Y TO WIDTH AND HEIGHT

int main()
{
    freopen("input.txt", "r", stdin);

    while (1)
    {
        scanf("%d %d", &W, &H);

        if (W == 0 && H == 0)
            break;

        CNT = 0;

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                scanf("%d", &MAP[i][j]);
                VISITED[i][j] = false;
            }
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (VISITED[i][j] == false && MAP[i][j])
                {
                    DPS(j, i);
                    //PUSH_COUNT(MAX);
                    CNT++;
                }
            }
        }

        printf("%d\n", CNT);
    }

    return 0;
}