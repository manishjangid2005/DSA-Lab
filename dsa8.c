#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPos(struct Node** head, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (pos == 1) {
        
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        free(newNode);
        printf("Position out of range.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void traverse(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Count\n5. Exit\nChoose: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
            case 1:
                printf("Data: "); scanf("%d", &data);
                printf("Position: "); scanf("%d", &pos);
                insertAtPos(&head, data, pos);
                break;
            case 2:
                printf("Delete position: "); scanf("%d", &pos);
                deleteNode(&head, pos);
                break;
            case 3: traverse(head); break;
            case 4: printf("Count: %d\n", countNodes(head)); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
