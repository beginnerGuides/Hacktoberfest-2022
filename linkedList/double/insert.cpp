#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *pre;
    Node *next;
};
struct Node *head, *tail;
void createList(char val)
{
    // create new node
    Node *new_node = new Node();
    new_node->data = val;
    new_node->pre = NULL;
    new_node->next = NULL;

    // initially no any node is created so head is NULL
    if (head == NULL)
    {
        head = tail = new_node;
    }
    // after creating first node head contain address of first node
    else
    {
        tail->next = new_node;
        new_node->pre = tail;
        tail = new_node;
    }
}

void insertBeg(char ch)
{
    Node *new_node = new Node();
    new_node->data = ch;
    new_node->pre = NULL;
    new_node->next = NULL;
    // if there is no any node then
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->pre = new_node;
        head = new_node;
    }
}
void insertAtEnd(char ch)
{
    Node *new_node = new Node();
    new_node->data = ch;
    new_node->pre = NULL;
    new_node->next = NULL;
    tail->next = new_node;
    new_node->pre = tail;
    tail = new_node;
}
int count()
{
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
void insertAtAnyPos(int pos, char ch)
{
    Node *new_node = new Node();
    new_node->data = ch;
    new_node->pre = NULL;
    new_node->next = NULL;
    // take a temp pointer to store head address
    Node *temp = head;
    if (pos < 1 || pos > count() + 1)
    {
        cout << pos;
        return;
    }
    else
    {
        if (pos == 1)
            insertBeg(ch);

        else
        {
            cout << pos << endl;
            for (int i = 1; i < pos - 1; i++)
            {
                cout << i << endl;
                temp = temp->next;
            }
            cout << pos << endl;
            new_node->next = temp->next;
            new_node->pre = temp;
            // if node is not  last node
            if (temp->next)
            {
                cout << pos << endl;
                temp->next = new_node;
                new_node->next->pre = new_node;
            }
            else
            {
                temp->next = new_node;
            }
        }
    }
}
void insertAfterAnyPos()
{
    int pos;
    cout << "enter the postion: ";
    cin >> pos;
    int len = count();
    cout << len;
    if (pos < 1 || pos > len)
        return;
    else
    {
        char ch;
        cout << "Enter the value: ";
        cin >> ch;
        Node *new_node = new Node();
        new_node->data = ch;
        new_node->pre = NULL;
        new_node->next = NULL;
        // take a temp pointer to store head address
        Node *temp = head;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->pre = temp;
        temp->next = new_node;
        new_node->next->pre = new_node;
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
int main()
{
    createList('A');
    createList('B');
    createList('C');
    display();
    cout << "Inserting operation goes here: " << endl;
    // insertBeg('Z');
    // display();
    // cout << endl;
    // insertAtEnd('G');
    // display();
    cout << endl;
    insertAtAnyPos(4, 'g');
    display();
    // cout << endl;
    // insertAfterAnyPos();
    // display();
    return 0;
}
