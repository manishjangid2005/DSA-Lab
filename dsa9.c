#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void displayLL(struct Node *first, int data) {
    printf("%d", first->data);
    first = first->next;
}

struct Node *insertAtBeg(struct Node *first, int data) {
    struct Node *node = (struct Node *) malloc (sizeof(struct Node));
    node->data = data;
    node->next = first;
}

int main(int argc, char const *argv[])
{
    struct Node *first = (struct Node *) malloc (sizeof(struct Node));
    struct Node *second = (struct Node *) malloc (sizeof(struct Node));
    struct Node *third = (struct Node *) malloc (sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc (sizeof(struct Node));

    first->data = 4;
    first->next = second;
    second->data = 5; 
    second->next = third;
    third->data = 6; 
    third->next = fourth;
    fourth->data = 7; 
    fourth->next = NULL;

    insertAtBeg(first, 2);

    return 0;
}

