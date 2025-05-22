#include <stdio.h>

#define MAX_SIZE 100

typedef struct Stack
{
    int arr[MAX_SIZE];
    int top_index;
}Stack;

void init(Stack* stack)
{
    stack->top_index = -1;
}

int isEmpty(Stack* stack)
{
    if(stack->top_index == -1)
        return 1;

    return 0;
}

