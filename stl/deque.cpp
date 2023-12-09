// properties of deque stl

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    cout << "Size of deque is : " << d.size() << endl;
    cout << "Max size of deque is : " << d.max_size() << endl;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    cout << "Size of deque is : " << d.size() << endl;
    cout << "Max size of deque is : " << d.max_size() << endl;

    cout << "Element at 2nd index is : " << d.at(2) << endl;
    cout << "Element at 2nd index is : " << d[2] << endl;
    cout << "First element is : " << d.front() << endl;
    cout << "Last element is : " << d.back() << endl;

    cout << "Before pop : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.pop_back();

    cout << "After back pop : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.pop_front();

    cout << "After front pop : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "Before clear : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    d.clear();

    cout << "After clear : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "Size of deque is : " << d.size() << endl;
    cout << "Max size of deque is : " << d.max_size() << endl;

    return 0;
}