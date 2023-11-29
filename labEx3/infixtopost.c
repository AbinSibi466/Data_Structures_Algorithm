#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    if (top < 99)
        stack[++top] = x;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0'; // Return null character for empty stack
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

void infixToPostfix(char exp[]) {
    char postfix[100];
    int i, j;
    for (i = 0, j = 0; exp[i] != '\0'; i++) {
        if (isalpha(exp[i])) {
            postfix[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1) {
                pop(); // Pop '(' from the stack
            }
        } else {
            while (top != -1 && precedence(exp[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(exp[i]);
        }
    }
    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    int opt;
    char exp[100] = ""; // Initialize infix expression

    while (1) {
        printf("\n +--------------Movie Ticket Booking-------------+\n");
        printf(" | 1. Enter Ticket Booking Expression             |\n");
        printf(" | 2. Display Postfix Expression                 |\n");
        printf(" | 3. Exit                                       |\n");
        printf(" +-----------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the ticket booking expression (e.g., A+B*C-(D/E)): ");
                scanf("%s", exp);
                break;
            case 2:
                printf("Infix Expression: %s\n", exp);
                infixToPostfix(exp);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}
