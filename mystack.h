#include <iostream>
using namespace std;

class Stack
{
private:
    int value;
    Stack *next;
    static Stack *topNode;

public:
    Stack(int data = 0)
    {
        topNode = this;
        this->value = data;
        this->next = nullptr;
    }

    void push(int data)
    {
        Stack *newElement = new Stack(data);

        if (!newElement)
        {
            cout << "Stack Overflow";
            return;
        }

        Stack *curr = this;
        while (curr->next != nullptr)
            curr = curr->next;

        curr->next = newElement;
    }

    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        if (this->next == nullptr)
        {
            topNode = nullptr;
            cout << "Data Popped: " << this->value << endl;
            delete this;
            return;
        }

        Stack *curr = this;
        Stack *prev = nullptr;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        cout << "Data Popped: " << curr->value << endl;
        delete curr;
        topNode = prev;
        prev->next = nullptr;
    }

    Stack *top() { return topNode; }

    bool isEmpty()
    {
        if (topNode == nullptr)
            return true;
        else
            return false;
    }

    int size()
    {
        if (topNode == nullptr)
            return 0;

        if (this->next == nullptr)
            return 1;

        return 1 + this->next->size();
    }

    void printStack()
    {
        if (topNode == nullptr)
        {
            cout << "Stack Empty" << endl;
            return;
        }

        if (this == nullptr)
            return;

        cout << this->value;
        if (this->next == nullptr)
            cout << endl;
        else
        {
            cout << " -> ";
            this->next->printStack();
        }
    }
};

Stack *Stack::topNode = nullptr;