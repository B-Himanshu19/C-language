#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int item) {
    stack[++top] = item;
}
int pop() {
    return stack[top--];
}
int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    int operand1, operand2;
    for (char *symbol = expression; *symbol != '\0'; symbol++) {
        if (*symbol >= '0' && *symbol <= '9') {
            push(*symbol - '0');
        } else if (*symbol == '+' || *symbol == '-' || *symbol == '*' || *symbol == '/') {
            operand2 = pop();
            operand1 = pop();
            switch (*symbol) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
            }
        } else if (*symbol == '(' || *symbol == ')') {
            // Handle parentheses if needed
            // You can choose to evaluate expressions inside parentheses
            // or handle them according to your requirements
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
