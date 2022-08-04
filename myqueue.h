#include <iostream>
using namespace std;

class Queue
{
private:
    int value;
    Queue *next;
    static Queue *rearNode;
    static Queue *frontNode;

public:
    Queue(int data = 0)
    {
        this->value = data;
        this->next = rearNode;

        rearNode = this;
    }

    void push(int data, Queue *&head)
    {
        if (rearNode)
        {
            if (rearNode->next == nullptr)
                frontNode = rearNode;
        }
        else
            frontNode = nullptr;

        Queue *newElement = new Queue(data);

        if (!newElement)
        {
            cout << "Queue Overflow";
            return;
        }

        head = newElement;
    }

    void pop(Queue *&head)
    {
        if (rearNode == nullptr)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        Queue *curr = rearNode;
        rearNode = rearNode->next;
        head = rearNode;

        cout << "Data Popped: " << curr->value << endl;
        delete curr;
    }

    Queue *front() { return frontNode; }

    bool isEmpty()
    {
        if (rearNode == nullptr)
            return true;
        else
            return false;
    }

    int size()
    {
        if (rearNode == nullptr)
            return 0;

        if (this->next == nullptr)
            return 1;

        return 1 + this->next->size();
    }

    void printQueue()
    {
        if (rearNode == nullptr)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << this->value;
        if (this->next == nullptr)
            cout << endl;
        else
        {
            cout << " -> ";
            this->next->printQueue();
        }
    }
};

Queue *Queue::rearNode = nullptr;
Queue *Queue::frontNode = nullptr;