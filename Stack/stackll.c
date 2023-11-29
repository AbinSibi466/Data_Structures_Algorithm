#include <stdio.h>
#include <stdlib.h>

// Node structure to represent each element in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top; // Points to the top of the stack
};

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top; // Make the new node the new top
    stack->top = newNode;
    printf("%d pushed to the stack\n", data);
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    struct Node* poppedNode = stack->top;
    int poppedValue = poppedNode->data;
    stack->top = poppedNode->next; // Move the top to the next node
    free(poppedNode);
    printf("%d popped from the stack\n", poppedValue);
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a default value indicating an empty stack
    }
    return stack->top->data;
}

// Main function to test the stack implementation
int main() {
    struct Stack* stack = createStack();

    // Pushing elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Peeking at the top element
    printf("Top element: %d\n", peek(stack));

    // Popping elements from the stack
    pop(stack);
    pop(stack);
    pop(stack);

    // Attempting to pop from an empty stack
    pop(stack);

    free(stack); // Don't forget to free the allocated memory for the stack

    return 0;
}
   