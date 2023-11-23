#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;
void push(int n)
{
    if (top == MAX - 1)
        printf("Stack is full\n");
    else if (top == -1)
        stack[++top] = n;
    else
    {
        int tempstack[MAX], temptop = -1;
        while (n > stack[top] && top != -1)
            tempstack[++temptop] = stack[top--];
        stack[++top] = n;
        while (temptop > -1)
            stack[++top] = tempstack[temptop--];
    }
}
void pop()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("\nPopped element : %d\n", stack[top--]);
}
void dispStack()
{
    printf("\n");
    for (int i = 0; i <= top; i++)
        printf("%d\t", stack[i]);
}
int main()
{
    int option = 0, element;
    while (option != 4)
    {
        printf("\n** Menu **\n1.Push\n2.Pop\n3.Display Stack\n4.Exit\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            dispStack();
            break;
        case 4:
            printf("Exiting");
            break;
        default:
            printf("Invalid input");
        }
    }
}