#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printLinkedListData(struct Node *ptr) {
    while (ptr != NULL) {
        printf("\nElement: %d", ptr->data);
        ptr = ptr->next;
    }
}

void insertNode(struct Node **head, int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Invalid position.\n");
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main() {
    struct Node *head = NULL;
    int data, position, i;
    char response[3];

    for (i = 1; i <= 12; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertNode(&head, data, i);

        printf("Do you want to insert another node (yes/no)? ");
        scanf("%s", response);

        if (response[0] == 'n' || response[0] == 'N') {
            break;
        }
    }

    printf("\nLinked List Data:\n");
    printLinkedListData(head);

    // Free all the allocated heap memory
    while (head) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

