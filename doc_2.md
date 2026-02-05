# Documentation for prog_2.c

## Problem Statement
Convert infix expressions to postfix notation and evaluate the postfix expression.

## Data Structures

### CharStack
- **Purpose**: Store operators during conversion
- **Fields**:
  - `char data[MAX]`: Array to store operators
  - `int top`: Top index

### IntStack
- **Purpose**: Store operands during evaluation
- **Fields**:
  - `int data[MAX]`: Array to store integers
  - `int top`: Top index

## Key Functions

### Conversion Functions
- `int precedence(char op)`: Returns operator precedence (1 for +/-, 2 for */,  3 for ^)
- `int isOperator(char ch)`: Checks if character is an operator
- `void infixToPostfix(char *infix, char *postfix)`: Converts infix to postfix using stack

### Evaluation Functions
- `int evaluatePostfix(char *postfix)`: Evaluates postfix expression and returns result

## Infix to Postfix Algorithm
1. Scan infix expression left to right
2. If operand, add to postfix
3. If '(', push to stack
4. If ')', pop until '(' is found
5. If operator, pop operators with higher/equal precedence, then push current operator
6. After scanning, pop all remaining operators

## Postfix Evaluation Algorithm
1. Scan postfix expression left to right
2. If operand, push to stack
3. If operator, pop two operands, apply operation, push result
4. Final stack value is the result

## Time Complexity
- **Conversion**: O(n) where n is length of expression
- **Evaluation**: O(n) where n is length of postfix expression

## Sample Output
```
Infix to Postfix Converter and Evaluator
==========================================

Enter an infix expression (use single digits): 2+3*4
Postfix expression: 234*+
Result: 14
```

## Limitations
- Works with single-digit operands
- Right associativity not fully supported for ^
- No error handling for invalid expressions

## Possible Enhancements
- Support multi-digit numbers
- Add error checking for invalid operators
- Implement prefix notation conversion
- Support variables in expressions
