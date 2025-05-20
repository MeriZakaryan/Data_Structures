#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct List
{
    Node* head;
    Node* tail;
    int size;
}List;


Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void initList(List* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void push_back(List* list, int value)
{
    Node* node = createNode(value);

    if(list->head == NULL && list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else 
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    ++list->size;
}

void push_front(List* list, int value)
{
    Node* node = createNode(value);

    if(list->head == NULL && list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else 
    {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }

    ++list->size;
}

void pop_back(List* list)
{
    if(list->head == NULL && list->tail == NULL)
    {
        return;
    }

}

void pop_front(List* list)
{

}

int getSize(List* list)
{

}

void printList(List* list)
{

}


int main()
{

    return 0;
}