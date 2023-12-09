// bubble sort with given arr , n ;

#include<iostream>
using namespace std ;

// void bubbleSort(int arr[] , int n){
//     for(int i=0; i< n; i++){
//         for(int j = i ; j <n ; j++){
//             if(arr[j+1] < arr[j]){
//                 swap(arr[j], arr[j+1]) ;
//             }
//         }
//     }
// }

void bubbleSort(int arr[] , int n){
    for(int i=1; i< n ; i++){
        for(int j = 0 ; j <n-i ; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j], arr[j+1]) ;
            }
        }
    }
}

int main(){
    int arr[6] = {0, 15, 1, 7, 10, 9};
    int n = 6;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity : O(n^2)
