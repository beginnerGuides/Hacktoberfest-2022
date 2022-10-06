#include <iostream>
using namespace std;

class linkedList
{
    int data;
    linkedList *next;
    linkedList *head;
    linkedList *temp;

public:
    linkedList()
    {
        head = NULL;
        temp = NULL;
    }
    void createList(int data)
    {
        linkedList *newNode = new linkedList();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    void display()
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void countNode();
    void sumOfElement();
    void maxEle();
    void minEle();
};

void linkedList::countNode()
{
    cout << "Number of nodes you enter is ";
    temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << count;
}
void linkedList::sumOfElement()
{
    cout << endl;
    cout << "Sum of all element of the all nodes ";
    temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    cout << sum;
}

void linkedList::maxEle()
{
    cout << endl;
    int max = 0;
    temp = head;
    cout << "The maximum element of the linked list is ";
    while (temp != NULL)
    {
        if (max <= temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    cout << max;
}
void linkedList::minEle()
{
    cout << endl;
    int min = 0;
    temp = head;
    cout << "The mininum element of the linked list is ";
    while (temp != NULL)
    {
        if (min >= temp->data)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    cout << min;
}
int main()
{
    linkedList li;
    li.createList(5);
    li.createList(50);
    li.createList(8);
    li.createList(-8);
    li.display();
    li.countNode();
    li.sumOfElement();
    li.maxEle();
    li.minEle();
    return 0;
}