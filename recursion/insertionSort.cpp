// insertion sort using recursion

#include <iostream>
using namespace std;

void rInsertionSort(int *arr , int n){
    if(n == 1 || n == 0){
        return ;
    }

    rInsertionSort(arr , n-1) ;

    int temp = arr[n-1] ;  // last element
    int j = n-2 ;           // second last element
    while(arr[j] > temp && j >= 0){
        arr[j+1] = arr[j] ;  // shift the element to the right
        j-- ;   // move to the left
    }
    arr[j+1] = temp ; // insert the element at the right position
}

int main()
{
    int arr[6] = {0, 15, 1, 7, 10, 9};
    int n = 6 ;

    rInsertionSort(arr , n) ;

    return 0;
}