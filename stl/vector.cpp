// vector stl

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    cout << "Capacity of vector is : " << v.capacity() << endl;
    cout << "Size of vector is : " << v.size() << endl;

    v.push_back(1);

    cout << "Capacity of vector is : " << v.capacity() << endl;
    cout << "Size of vector is : " << v.size() << endl;

    v.push_back(2);
    cout << "Size of vector is : " << v.size() << endl;

    cout << "Capacity of vector is : " << v.capacity() << endl;
    v.push_back(3);

    cout << "Size of vector is : " << v.size() << endl;
    cout << "Capacity of vector is : " << v.capacity() << endl;
    cout << "Max size of vector is : " << v.max_size() << endl;

    

    cout << "Element at 2nd index is : " << v.at(2) << endl;
    cout << "Element at 2nd index is : " << v[2] << endl;
    cout << "First element is : " << v.front() << endl;
    cout << "Last element is : " << v.back() << endl;

    cout << "Before pop : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();

     // points to first element

    cout << "After pop : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Before clear : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.clear();

    cout << "After clear : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Empty or not : " << v.empty() << endl;

    return 0;
}