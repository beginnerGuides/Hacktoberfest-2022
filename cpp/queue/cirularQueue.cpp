#include <iostream>
#include <vector>
#define s 4;
using namespace std;
class MyCircularQueue
{
public:
    vector<int> v;
    int tail;
    int head;
    int size;
    MyCircularQueue(int k)
    {                // initialize with values
        v.resize(k); // given size to array
        tail = head = -1;
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (head == -1)
            head = 0;
        tail = (tail + 1) % size;
        v[tail] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        // when head and tail at same position
        if (head == tail)
        {
            head = tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return v[head];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return v[tail];
    }

    bool isEmpty()
    {
        if (head == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        return (((tail + 1) % size) == head);
    }
};

int main()
{
    MyCircularQueue cq(3);
    cout << cq.enQueue(41) << endl;
    cout << cq.enQueue(4) << endl;
    cout << cq.enQueue(40) << endl;
    cout << "front element: " << cq.Front() << endl;
    cout << "rear element: " << cq.Rear() << endl;
    cout << cq.deQueue() << endl;
    return 0;
}