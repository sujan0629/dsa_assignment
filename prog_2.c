#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for characters
typedef struct {
    char data[MAX];
    int top;
} CharStack;

// Stack for integers
typedef struct {
    int data[MAX];
    int top;
} IntStack;

// Initialize character stack
void initCharStack(CharStack *s) {
    s->top = -1;
}

// Initialize integer stack
void initIntStack(IntStack *s) {
    s->top = -1;
}

// Check if character stack is empty
int isCharEmpty(CharStack *s) {
    return s->top == -1;
}

// Check if integer stack is empty
int isIntEmpty(IntStack *s) {
    return s->top == -1;
}

// Push to character stack
void pushChar(CharStack *s, char ch) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = ch;
    }
}

// Push to integer stack
void pushInt(IntStack *s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

// Pop from character stack
char popChar(CharStack *s) {
    if (!isCharEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Pop from integer stack
int popInt(IntStack *s) {
    if (!isIntEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0;
}

// Peek character stack
char peekChar(CharStack *s) {
    if (!isCharEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// Get operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int j = 0;
    
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        
        // Skip spaces
        if (ch == ' ') continue;
        
        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isCharEmpty(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
            }
            if (!isCharEmpty(&s)) popChar(&s); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!isCharEmpty(&s) && precedence(peekChar(&s)) >= precedence(ch)) {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }
    
    // Pop remaining operators
    while (!isCharEmpty(&s)) {
        postfix[j++] = popChar(&s);
    }
    
    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char *postfix) {
    IntStack s;
    initIntStack(&s);
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        // If operand, push to stack
        if (isdigit(ch)) {
            pushInt(&s, ch - '0');
        }
        // If operator, pop two operands and apply operation
        else if (isOperator(ch)) {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            int result;
            
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int p = 0; p < val2; p++) result *= val1;
                    break;
                }
            }
            pushInt(&s, result);
        }
    }
    
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Infix to Postfix Converter and Evaluator\n");
    printf("==========================================\n\n");
    printf("Enter an infix expression (use single digits): ");
    fgets(infix, MAX, stdin);
    
    // Remove newline
    infix[strcspn(infix, "\n")] = 0;
    
    // Convert to postfix
    infixToPostfix(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);
    
    // Evaluate
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}
