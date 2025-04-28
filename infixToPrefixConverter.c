#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void swapBrackets(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infixToPrefix(char *infix, char *prefix) {
    char temp[MAX];
    int j = 0;

    reverse(infix);
    swapBrackets(infix);

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            temp[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                temp[j++] = pop();
            }
            pop(); // remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                temp[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        temp[j++] = pop();
    }

    temp[j] = '\0';
    reverse(temp);
    strcpy(prefix, temp);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
