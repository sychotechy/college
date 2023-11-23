/*
Postfix Evaluation
Name :- Sreejith O
Class :- CS3B
Roll no :- 71
*/
#include <stdio.h>
int stack[20], top = -1;
char postfix[20];
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
int eval()
{
    int i, n1, n2, n3;
    char c;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        c = postfix[i];
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
            push((int)c - 48);
        else
        {
            n1 = pop();
            n2 = pop();
            switch (c)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            push(n3);
        }
    }
    return pop();
}
int main()
{
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("The result is %d", eval());
}
