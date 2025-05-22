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
    {
        printf("Stack is empty.\n");
        return 1;
    }

    return 0;
}

int isFull(Stack* stack)
{
    if(stack->top_index == MAX_SIZE - 1)
    {
        printf("Stack is full.\n");
        return 1;
    }

    return 0;
}

int top(Stack* stack)
{
    if(isEmpty(stack)) return -1;

    return stack->arr[stack->top_index];
}

void push(Stack* stack, int value)
{
    if(isFull(stack)) return;

    ++stack->top_index;
    stack->arr[stack->top_index] = value; 
}

void pop(Stack* stack)
{
    if(isEmpty(stack)) return;

    --stack->top_index;
}

void printStack(Stack* stack)
{
    for(int i = 0; i <= stack->top_index; ++i)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("The top is: %d\n", top(&stack));
    printStack(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    printf("The top is: %d\n", top(&stack));
    printStack(&stack);

}