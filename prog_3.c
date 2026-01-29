#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Forward traversal
void forwardTraversal(Node *head) {
    printf("Forward: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse traversal using recursion
void reverseTraversalRecursive(Node *head) {
    if (head == NULL) return;
    
    reverseTraversalRecursive(head->next);
    printf("%d ", head->data);
}

// Reverse traversal wrapper
void reverseTraversal(Node *head) {
    printf("Reverse: ");
    reverseTraversalRecursive(head);
    printf("\n");
}

// Reverse the linked list itself
Node* reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Display menu
void displayMenu() {
    printf("\n--- Linked List Reverse Traversal ---\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Forward traversal\n");
    printf("4. Reverse traversal\n");
    printf("5. Reverse the list\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Node *head = NULL;
    int choice, data;
    
    printf("Linked List with Reverse Traversal\n");
    printf("===================================\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Inserted %d at beginning\n", data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Inserted %d at end\n", data);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    forwardTraversal(head);
                }
                break;
                
            case 4:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    reverseTraversal(head);
                }
                break;
                
            case 5:
                if (head == NULL) {
                    printf("List is empty!\n");
                } else {
                    head = reverseList(head);
                    printf("List reversed!\n");
                    forwardTraversal(head);
                }
                break;
                
            case 6:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
