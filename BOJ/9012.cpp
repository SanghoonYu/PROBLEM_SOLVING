#include <iostream>

using namespace std;

char ORG_STR[51];
int STACK_SIZE = 0;

void stack_push()
{
    STACK_SIZE++;
}

void stack_pop()
{
    STACK_SIZE--;
}

bool stack_empty()
{
    if (STACK_SIZE == 0)
        return true;
    return false;
}

void stack_clear()
{
    STACK_SIZE = 0;
}

int main()
{
    int N;
    bool result = false;

    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    while (N-- > 0) {
        scanf("%s", ORG_STR);
        int i = 0;
        result = false;
        while (ORG_STR[i] != '\0') {
            if (ORG_STR[i] == '(')
                stack_push();
            else if (ORG_STR[i] == ')')
                stack_pop();
            
            if (STACK_SIZE < 0) {
                result = false;
                break;
            }
            i++;
        }

        if (stack_empty())
            result = true;
        
        if (result) 
            printf("YES\n");
        else 
            printf("NO\n");
        
        stack_clear();
    }

    return 0;
}
