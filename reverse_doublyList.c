#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

void printNodes(Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node* reverse(Node* head)
{
    Node* current = head;
    Node* tmp = NULL;

    while(current != NULL)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    return tmp ? tmp -> prev: head;
}

int main()
{
    Node a, b, c, d;
    a.value = 1;
    b.value = 2;
    c.value = 3; 
    d.value = 4;

    a.prev = NULL;
    a.next = &b;

    b.prev = &a;
    b.next = &c;

    c.prev = &b;
    c.next = &d;

    d.prev = &c;
    d.next = NULL;

    printNodes(&a);

    Node* new_head = reverse(&a);
    printNodes(new_head);
    return 0;
}