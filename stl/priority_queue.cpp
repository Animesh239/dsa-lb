// properties of priority queue stl

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq;

    // min heap
    // priority_queue<int, vector<int>, greater<int>> pq;


    cout << "Size of priority queue is : " << pq.size() << endl;
    // cout << "Max size of priority queue is : " << pq.max_size() << endl;

    pq.push(1);
    pq.push(20);
    pq.push(3);
    pq.push(4);

    cout << "Size of priority queue is : " << pq.size() << endl;
    // cout << "Max size of priority queue is : " << pq.max_size() << endl;

    cout << "Top element is : " << pq.top() << endl;


    cout << "Before pop : " << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    cout << "After pop : " << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}