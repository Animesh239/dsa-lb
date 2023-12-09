// properties of queue stl

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    cout << "Size of queue is : " << q.size() << endl;
    // cout << "Max size of queue is : " << q.max_size() << endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Size of queue is : " << q.size() << endl;
    // cout << "Max size of queue is : " << q.max_size() << endl;

    cout << "Front element is : " << q.front() << endl;
    cout << "Back element is : " << q.back() << endl;

    //emplace
    q.emplace(5); // it will add the element at the end of the queue
    // //Function         Description
    //  emplace()         Constructs a new object in-place at the end of the queue.
    //  push()            Adds a copy of the object to the end of the queue.

    cout << "Before pop : " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
        
    }
    cout << endl;

    cout << "After pop : " << endl;
    while (!q.empty())
    {
        cout << q.front() << " " << endl;
        q.pop();
    }
    cout << endl;
    // After pop :  // nothing will be printed as i have popped all the elements to show teh before pop and after pop difference

    return 0;
}