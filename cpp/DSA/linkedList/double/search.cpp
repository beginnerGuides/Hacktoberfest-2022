#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *pre;
    Node *next;
};
struct Node *head;
void createList(char val)
{
    // create new node
    Node *new_node = new Node();
    new_node->data = val;
    new_node->pre = NULL;
    new_node->next = NULL;

    // take a new node as temp
    Node *temp;
    // initially no any node is created so head is NULL
    if (head == NULL)
    {
        head = temp = new_node;
    }
    // after creating first node head contain address of first node
    else
    {
        temp->next = new_node;
        new_node->pre = temp;
        temp = new_node;
    }
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int find(char ch)
{
    Node *t = head;
    while (t != NULL)
    {
        if (t->data == ch)
            return 1;
        t = t->next;
    }
    return 0;
}

int main()
{
    createList('A');
    createList('B');
    createList('C');
    display();
    cout << endl;
    cout << find('z');
    return 0;
}
