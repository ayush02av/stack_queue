#include <iostream>
#include "mystack.h"
#include "myqueue.h"
using namespace std;

int main()
{
    int choice = 1;

    cout << "STACKS AND QUEUES | Main Menu"
         << "\n\n1. Stack"
         << "\n2. Queue"
         << "\nEnter Choice (1 or 2): ";
    cin >> choice;

    while (choice != 1 && choice != 2)
    {
        cout << "\nWrong Choice!"
             << "\nEnter Choice (1 or 2):";
        cin >> choice;
    }
    cout << "\n\n";

    int innerChoice;
    switch (choice)
    {
    case 1:
        Stack *stack;

        do
        {
            cout << "\n\nStack Menu"
                 << "\n0. Exit"
                 << "\n1. Print Stack"
                 << "\n2. Print Size"
                 << "\n3. Print Top"
                 << "\n4. Push"
                 << "\n5. Pop"
                 << "\n6. Check If Empty"
                 << "\nEnter: ";
            cin >> innerChoice;

            while (innerChoice < 0 || innerChoice > 6)
            {
                cout << "\nWrong Choice!"
                     << "\nEnter Choice (0 to 6):";
                cin >> innerChoice;
            }

            switch (innerChoice)
            {
            case 1:
                stack->printStack();
                break;

            case 2:
                cout << "Size of the stack: " << stack->size() << endl;
                break;

            case 3:
                stack->top()->printStack();
                break;

            case 4:
                int data;
                cout << "Enter New Data Value: ";
                cin >> data;

                if (stack->isEmpty())
                    stack = new Stack(data);
                else
                    stack->push(data);
                break;

            case 5:
                stack->pop();
                break;

            case 6:
                cout << "Stack is Empty: ";

                if (stack->isEmpty())
                    cout << "True";
                else
                    cout << "False";
                cout << endl;

                break;
            }

        } while (innerChoice != 0);

        break;
    case 2:
        Queue *queue;

        do
        {
            cout << "\n\nQueue Menu"
                 << "\n0. Exit"
                 << "\n1. Print Queue"
                 << "\n2. Print Size"
                 << "\n3. Print Front"
                 << "\n4. Push"
                 << "\n5. Pop"
                 << "\n6. Check If Empty"
                 << "\nEnter: ";
            cin >> innerChoice;

            while (innerChoice < 0 || innerChoice > 6)
            {
                cout << "\nWrong Choice!"
                     << "\nEnter Choice (0 to 6):";
                cin >> innerChoice;
            }

            switch (innerChoice)
            {
            case 1:
                queue->printQueue();
                break;

            case 2:
                cout << "Size of the queue: " << queue->size() << endl;
                break;

            case 3:
                queue->front()->printQueue();
                break;

            case 4:
                int data;
                cout << "Enter New Data Value: ";
                cin >> data;

                if (queue->isEmpty())
                {
                    queue = new Queue(data);
                }
                else
                    queue->push(data, queue);
                break;

            case 5:
                queue->pop(queue);
                break;

            case 6:
                cout << "Queue is Empty: ";

                if (queue->isEmpty())
                    cout << "True";
                else
                    cout << "False";
                cout << endl;

                break;
            }

        } while (innerChoice != 0);

        break;
    }

    cout << "\n\nExiting...";
    return 0;
}