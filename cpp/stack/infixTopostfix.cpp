#include <iostream>
#define size 20
using namespace std;

char stack[100];
int top = -1;

void push(char x)
{
    if (top == size - 1)
    {
        cout << "stack is full" << endl;
    }
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
string infix_to_postfix(char *e)
{
    char x;
    string postfix;
    while (*e != '\0')
    {
        if (isalnum(*e))
            // printf("%c ", *e);
            postfix += *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')

            {
                // printf("%c ", x);
                postfix += x;
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                // printf("%c ", pop());
                postfix += pop();
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        // printf("%c ", pop());
        postfix += pop();
    }
    return postfix;
}
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    string result = infix_to_postfix(exp);
    cout << endl
         << result << endl;
    return 0;
}