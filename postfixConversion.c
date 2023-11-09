#include <stdio.h>
#define MAX 20
char stack[MAX], postfix[MAX], infix[MAX];
int top = -1;
void push(char x)
{
    if (top == MAX - 1)
        printf("Stack full\n");
    else
        stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void intopost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (top != -1 && priority(stack[top]) >= priority(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main()
{
    printf("Enter the infix expression:");
    scanf("%s", infix);
    intopost();
    printf("The postfix expression is: ");
    printf("%s", postfix);
}