#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char x)
{
    if (top < MAX - 1)
    {
        stack[++top] = x;
    }
}

int isEmpty()
{
    return top == -1;
}

char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    return '\0';
}

char peek()
{
    if (!isEmpty())
    {
        return stack[top];
    }
    return '\0';
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

void infToPos(char infix[], char postfix[])
{
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];
        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(token);
        }
        else if (token == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(peek()) >= precedence(token))
            {
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char postfix[MAX], infix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infToPos(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}