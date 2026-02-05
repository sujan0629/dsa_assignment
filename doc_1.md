# Documentation for prog_1.c

## Problem Statement
Check if a mathematical expression has balanced parentheses using a stack data structure.

## Data Structures

### Stack
- **Type**: Character stack
- **Size**: MAX = 100
- **Fields**:
  - `char data[MAX]`: Array to store parentheses
  - `int top`: Index of top element (-1 when empty)

## Functions

### `void initStack(Stack *s)`
Initializes the stack by setting `top` to -1.

### `int isEmpty(Stack *s)`
Returns 1 if stack is empty, 0 otherwise.

### `void push(Stack *s, char ch)`
Pushes a character onto the stack. Increments `top` and stores the character.

### `char pop(Stack *s)`
Removes and returns the top character from the stack. Returns '\0' if stack is empty.

### `int isOpening(char ch)`
Checks if a character is an opening parenthesis: '(', '{', or '['.

### `int isClosing(char ch)`
Checks if a character is a closing parenthesis: ')', '}', or ']'.

### `int isMatching(char open, char close)`
Checks if opening and closing parentheses match correctly.

### `int isBalanced(char *expr)`
Main algorithm to check if expression has balanced parentheses:
1. Scan expression left to right
2. Push opening parentheses onto stack
3. For closing parentheses, pop and check if they match
4. Expression is balanced if stack is empty at the end

## Main Method
1. Prompts user to enter a mathematical expression
2. Calls `isBalanced()` to check parentheses
3. Displays result (BALANCED or UNBALANCED)

## Algorithm Complexity
- **Time Complexity**: O(n) where n is the length of expression
- **Space Complexity**: O(n) for the stack in worst case

## Sample Output
```
Balanced Parentheses Checker
=============================

Enter a mathematical expression: {[()]}
Result: The expression has BALANCED parentheses.
```

```
Enter a mathematical expression: {[(])}
Result: The expression has UNBALANCED parentheses.
```

## Edge Cases Handled
- Empty expression
- Only opening parentheses
- Only closing parentheses
- Mismatched parentheses types
- Nested parentheses

## Implementation Notes
- Uses array-based stack for efficiency
- Fixed size stack (MAX = 100)
- Can be modified for dynamic sizing
