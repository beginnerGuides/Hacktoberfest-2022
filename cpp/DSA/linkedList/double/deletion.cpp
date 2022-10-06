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
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

void delete_index_element(int index)
{
    if (index < 1 || index > count())
        return;
    else
    {
        // first node
        char c;
        if (index == 1)
        {
            Node *q = head;
            head = head->next;
            c = q->data;
            delete (q);
            if (head)
                head->pre = NULL;
        }
        else
        {
            Node *q = head;
            for (int i = 1; i < index; i++)
            {
                q = q->next;
            }
            q->pre->next = q->next;
            // if it may be last node
            if (q->next)
                q->next = q->pre;
            char ch = q->data;
            cout << endl
                 << ch << endl;
            delete (q);
        }
    }
}
void deletion_of_ele(char x)
{
    Node *q = head;
    if (q->data == x)
    {
        q = head;
        head = head->next;
        head->pre = NULL;
        delete (q);
    }
    while (q != NULL)
    {
        if (q->data == x)
        {
            q->pre->next = q->next;
            if (q->next)
                q->next = q->pre;
            delete (q);
        }
        q = q->next;
    }
}

int main()
{
    createList('A');
    createList('B');
    createList('C');
    display();
    // cout << "\nAfter deleting the index of element:" << endl;
    // delete_index_element(3);
    // display();
    cout << "\nAfter deleteing the element of linked list:" << endl;
    deletion_of_ele('A');
    display();
    return 0;
}