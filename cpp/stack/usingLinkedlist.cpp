#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;
void push(int x)
{
    // create new node
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    // check for full or not
    if (newNode == NULL)
    {
        cout << "Stack is overflow ";
        return;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    Node *t = top;
    if (t == NULL)
    {
        cout << "Stack is empty";
        return;
    }
    else
    {
        t = top;
        top = top->next;
        delete (t);
    }
}

void display()
{
    Node *t = top;
    if (t == NULL)
    {
        cout << "Stack is empty";
        return;
    }
    else
    {
        while (t != NULL)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL";
    }
}
int main()
{
    push(5);
    push(56);
    push(60);
    display();
    pop();
    pop();
    pop();
    cout << "\n";
    display();
    return 0;
}