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

    if(list->head == list->tail || list->size == 1)
    {
        initList(list);
        return;
    }

    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;

    --list->size;
}

void pop_front(List* list)
{
    if(list->head == NULL && list->tail == NULL)
    {
        return;
    }

    if(list->head == list->tail || list->size == 1)
    {
        initList(list);
        return;
    }

    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;

    --list->size;
}

int getSize(List* list)
{
    return list->size;
}

void printList(List* list)
{
    if(list->head == NULL)
    {
        printf("The list is empty.\n");
    }

    Node* current = list->head;

    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\nThe size of the list is %d. \n", getSize(list));
}

int main()
{
    List list;
    initList(&list);

    push_back(&list, 1);
    push_back(&list, 2);
    push_back(&list, 3);

    push_front(&list, 4);
    push_front(&list, 5);
    push_front(&list, 6);

    printList(&list);

    pop_back(&list);
    pop_front(&list);
    pop_front(&list);

    printList(&list);

    return 0;
}