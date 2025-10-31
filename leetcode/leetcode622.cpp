#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

struct Node
{
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyCircularQueue
{
private:
    int size, capacity;
    Node *front, *rear;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        size = 0;
        front = rear = nullptr;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        Node *newnode = new Node(value);
        if (isEmpty())
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        size--;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : front->val;
    }

    int Rear()
    {
        return isEmpty() ? -1 : rear->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};
