#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue
{
    int arr[MAX_SIZE];
    int front_index;
    int back_index;
}Queue;

void init(Queue* queue)
{
    queue->front_index = -1;
    queue->back_index = -1;
}

int isEmpty(Queue* queue)
{
    if(queue->front_index == -1 || queue->front_index > queue->back_index)
    {
        printf("Queue is empty.\n");
        return 1;
    }

    return 0;
}

int isFull(Queue* queue)
{
    if(queue->back_index == MAX_SIZE - 1)
    {
        printf("Queue is full.\n");
        return 1;
    }
    return 0;
}

void enqueue(Queue* queue, int value)
{
    if(isFull(queue)) return;

    if(queue->front_index == -1)
    {
        queue->front_index = 0;
    }

    ++queue->back_index;
    queue->arr[queue->back_index] = value;
}

void dequeue(Queue* queue)
{
    if(isEmpty(queue)) return;

    ++queue->front_index;
    
    if(queue->front_index > queue->back_index)
        init(queue);
}

int getFront(Queue* queue)
{
    if(isEmpty(queue)) return -1;

    return queue->arr[queue->front_index];
}

void printQueue(Queue* queue)
{
    int index = queue->front_index;
    while(queue->arr[index])
    {
        printf("%d ", queue->arr[index]);
        index++;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    init(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printQueue(&queue);

    dequeue(&queue);
    dequeue(&queue);

    printQueue(&queue);
    printf("The front is: %d\n", getFront(&queue));
}