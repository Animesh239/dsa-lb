// implement a doubly ended queue using arrays and implement the following functions : push_back(), push_front(), pop_back(), pop_front(), front(), back(), empty(), size(), isFull()

#include <iostream>
#include <vector>
using namespace std;

class Deque
{
    vector<int> dq;
    int front, rear;
    int n;

public:
    // Initialize your data structure.
    Deque(int size) : dq(size), front(-1), rear(-1), n(size) {} // {} is the default constructor

    // Helper function to check if the deque is empty.
    bool isEmpty()
    {
        return front == -1;
    }

    // Helper function to check if the deque is full.
    bool isFull()
    {
        return (front == 0 && rear == n - 1) || (front == rear + 1);
    }

    // Helper function to increment or decrement indices in a circular manner.
    int circularIncrement(int index)
    {
        return (index + 1) % n;
    }

    int circularDecrement(int index)
    {
        return (index - 1 + n) % n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else
            front = circularDecrement(front);

        dq[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else
            rear = circularIncrement(rear);

        dq[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
            return -1;

        int item = dq[front];

        if (front == rear) 
            front = rear = -1;
        else
            front = circularIncrement(front);

        return item;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
            return -1;

        int item = dq[rear];

        if (front == rear)
            front = rear = -1;
        else
            rear = circularDecrement(rear);

        return item;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        return isEmpty() ? -1 : dq[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        return isEmpty() ? -1 : dq[rear];
    }
};