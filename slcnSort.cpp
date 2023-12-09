// an array with n elements . You have to sort them in non-decreasing order.

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i < n-1 ; i++){
        int min = i ;
        for(int j = i ; j < n ; j++){
            if(arr[j] < arr[min] ){
                min = j ;
            }
        }
        swap(arr[i] , arr[min]) ;
    }
}


int main()
{
    int arr[6] = {0, 15, 1, 7, 10, 9};
    int n = 6;

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity : O(n^2)