// properties of stack stl

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    cout << "Size of stack is : " << s.size() << endl;
    // cout << "Max size of stack is : " << s.max_size() << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Size of stack is : " << s.size() << endl;
    // cout << "Max size of stack is : " << s.max_size() << endl;

    cout << "Top element is : " << s.top() << endl;

    cout << "Before pop : " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "After pop : " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    //After pop :  // nothing will be printed as i have popped all the elements to show teh before pop and after pop difference


    return 0;
}