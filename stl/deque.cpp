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

    //erase function
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_back(5);

    cout << "Before erase in d1 : " << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    d1.erase(d1.begin() + 2); // erase 3rd element
    d1.erase(d1.begin(), d1.begin() + 3); // erase 1st 3 elements

    cout << "After erase in d1 : " << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    //insert function
    d1.insert(d1.begin() + 2, 3); // insert 3 at 3rd index

    d1.insert(d1.begin(), 2, 1); // insert 1 two times at beginning

    d1.insert(d1.begin(), d.begin(), d.end()); // insert all elements of d at beginning

    cout << "After insert in d1 : " << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    //swap function
    d1.swap(d);

    cout << "After swap in d1 : " << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    cout << "After swap in d : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;




    return 0;
}