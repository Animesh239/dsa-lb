// everything about pointers with array

#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {10, 20, 30};
    cout << arr << endl; // address of first element
    cout << *arr << endl; // value of first element
    cout << *(arr + 1) << endl; // value of second element
    cout << *(arr + 2) << endl; // value of third element

    // arr++; // invalid
    // arr = arr + 1; // invalid

    int *ptr = arr;
    cout << ptr << endl; // address of first element
    cout << *ptr << endl; // value of first element
    cout << *(ptr + 1) << endl; // value of second element
    cout << *(ptr + 2) << endl; // value of third element

    ptr++; // valid
    ptr = ptr + 1; // valid
    
    int i ;

    // arr[i] = *(arr + i) = *(ptr + i) = ptr[i] = i[arr] = i[ptr] = i[arr + i] = i[ptr + i] = *(arr + i[arr]) ; 

     // char arrays

    char carr[] = "abcd";
    cout << carr << endl; // abcd
    cout << *carr << endl; // a
    cout << *(carr + 3) << endl; // d
    cout << *(carr + 4) << endl; // garbage value

    

    
    return 0;
}