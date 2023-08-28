#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stk[MAX];
int top = -1;
int isEmpty() {
    return top == -1;
}
char peek() {
    return stk[top];
}
char pop() {
    if (isEmpty())
        return -1;
    return stk[top--];
}
void push(char oper) {
    if (top < MAX - 1)
        stk[++top] = oper;
}
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch) {
    return ch == '+' || ch == '-' ? 1 : (ch == '*' || ch == '/' ? 2 : (ch == '^' ? 3 : -1));
}
void infixToPostfix(char *expression) {
    int i, j = -1;
    for (i = 0; expression[i]; ++i) {
        if (isOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty() && peek() != '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return;
            pop();
        } else {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(expression[i]);
        }
    }
    while (!isEmpty())
        expression[++j] = pop();
    expression[++j] = '\0';
    printf("%s", expression);
}
int main() {
    char expression[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", expression);
    infixToPostfix(expression);
    return 0;
}
