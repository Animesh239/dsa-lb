// functions and pointers

#include <iostream>
using namespace std;

void print(int *ptr){
    cout << *ptr << endl;
}

int sum(int *arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += arr[i];  //  *(arr + i) = i[arr]
    }
    return ans;
}

void update(int *ptr){
    ptr = ptr + 1;
    cout << ptr << endl; // address of next element  is printed
}

int main(){

    int value = 5;
    int *ptr = &value;

    update(ptr);   // nothing happens // ptr is passed by value
    cout << ptr << endl; // same address as before

    // print(ptr) ;  // 5

    int arr[5] = {10, 20, 30, 40, 50};

   cout<< sum(arr+2, 5) << endl; // 30 + 40 + 50 = 120

    return 0;
}

// reason : ptr is passed by value and not by reference in update function
// so, ptr is copied to another variable ptr in update function but ptr in main function remains same