#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at beginning\n", data);
}

// Insert at end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at end\n", data);
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end\n", data);
}

// Insert at position
void insertAtPosition(Node **head, int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }
    
    Node *newNode = createNode(data);
    Node *temp = *head;
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, pos);
}

// Delete from beginning
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *temp = *head;
    
    // If only one node
    if (temp->next == NULL) {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    
    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

// Delete by value
void deleteByValue(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *temp = *head;
    
    // Find the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Value %d not found\n", value);
        return;
    }
    
    // If node to delete is head
    if (temp->prev == NULL) {
        deleteFromBeginning(head);
        return;
    }
    
    // If node to delete is last
    if (temp->next == NULL) {
        deleteFromEnd(head);
        return;
    }
    
    // Node in middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

// Display forward
void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display backward
void displayBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    // Go to last node
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Display menu
void displayMenu() {
    printf("\n--- Doubly Linked List Operations ---\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete by value\n");
    printf("7. Display forward\n");
    printf("8. Display backward\n");
    printf("9. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Node *head = NULL;
    int choice, data, pos;
    
    printf("Doubly Linked List Implementation\n");
    printf("==================================\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                break;
                
            case 4:
                deleteFromBeginning(&head);
                break;
                
            case 5:
                deleteFromEnd(&head);
                break;
                
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                break;
                
            case 7:
                displayForward(head);
                break;
                
            case 8:
                displayBackward(head);
                break;
                
            case 9:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
