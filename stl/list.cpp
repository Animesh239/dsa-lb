// properties of list stl   

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    cout << "Size of list is : " << l.size() << endl;
    cout << "Max size of list is : " << l.max_size() << endl;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    cout << "Size of list is : " << l.size() << endl;
    cout << "Max size of list is : " << l.max_size() << endl;

    // cout << "Element at 2nd index is : " << l.at(2) << endl;
    cout << "First element is : " << l.front() << endl;
    cout << "Last element is : " << l.back() << endl;

    cout << "Before pop : " << endl;
    for (int i :l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.pop_back();

    cout << "After back pop : " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.pop_front();

    cout << "After front pop : " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Before clear : " << endl;
    for (int i:l)
    {
        cout << i << " ";
    }
    cout << endl;

    l.clear();

    cout << "After clear : " << endl;
    for (int i :l)
    {
        cout << i << " ";
    }
    cout << endl;

    list<int> l1(5);
    cout << "Size of list is : " << l1.size() << endl;

    list<int> l2(5, 100);
    cout << "Size of list is : " << l2.size() << endl;

    cout << "L2 :" << endl;
    for (int i : l2)
    {
        cout << i << " ";
    }
    cout << endl;

    list<int> l3(l2);
    cout << "Size of list3 is : " << l3.size() << endl;

    cout << "L3 :" << endl;
    for (int i : l3)
    {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}