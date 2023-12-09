// different types of array stl

#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int, 5> arr = {1, 2, 3, 4, 5};

    cout << "Size of array is : " << arr.size() << endl;
    cout << "Max size of array is : " << arr.max_size() << endl;
    cout << "Element at 2nd index is : " << arr.at(2) << endl;
    cout << "Element at 2nd index is : " << arr[2] << endl;
    cout << "Empty or not : " << arr.empty() << endl;
    cout << "First element is : " << arr.front() << endl;
    cout << "Last element is : " << arr.back() << endl;
    
}