#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push element to stack
void push(Stack *s, char ch) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = ch;
    }
}

// Pop element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Check if character is opening parenthesis
int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Check if character is closing parenthesis
int isClosing(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Check if opening and closing parentheses match
int isMatching(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

// Check if expression has balanced parentheses
int isBalanced(char *expr) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(expr); i++) {
        if (isOpening(expr[i])) {
            push(&s, expr[i]);
        } else if (isClosing(expr[i])) {
            if (isEmpty(&s)) {
                return 0;
            }
            char top = pop(&s);
            if (!isMatching(top, expr[i])) {
                return 0;
            }
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char expr[MAX];
    
    printf("Balanced Parentheses Checker\n");
    printf("=============================\n\n");
    printf("Enter a mathematical expression: ");
    fgets(expr, MAX, stdin);
    
    // Remove newline character
    expr[strcspn(expr, "\n")] = 0;
    
    if (isBalanced(expr)) {
        printf("\nResult: The expression has BALANCED parentheses.\n");
    } else {
        printf("\nResult: The expression has UNBALANCED parentheses.\n");
    }
    
    return 0;
}
