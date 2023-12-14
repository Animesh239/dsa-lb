// all about double pointers

#include <iostream>
using namespace std;

void function(int **a){
    a = a + 1;
    cout << "1 " << a << endl;  // no changes

    *a = *a + 1;
    cout << "2 " << *a << endl; // changes to address of a

    **a = **a + 1;
    cout << "3 " << **a << endl;  // changes to value of a
}

int main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;

    cout << a << endl; // 10
    cout << &a << endl; // address of a
    cout << p << endl; // address of a
    cout << &p << endl; // address of p
    cout << *p << endl; // value of a
    cout << *(&a) << endl; // value of a
    cout << *(&p) << endl; // address of a
    cout << &(*p) << endl; // address of a
    cout << &(*(&a)) << endl; // address of a
    cout << &(*(&p)) << endl; // address of p
    cout << q << endl; // address of p
    cout << &q << endl; // address of q
    cout << *q << endl; // address of a
    cout << **q << endl; // value of a
    cout << &(*q) << endl; // address of p
    cout << &(**q) << endl; // address of a
   // cout << &(*(*(&a))) << endl; // address of a //not working // why? // because &a is not a pointer
    cout << &(*(*(&p))) << endl; // address of a
    cout << endl ;

    function(q);

    return 0;
}