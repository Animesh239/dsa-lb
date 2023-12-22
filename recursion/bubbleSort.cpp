// bubble sort normal and recursive

#include <iostream>
using namespace std ;

// normal
void bubbleSort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// recursive
void rBubbleSort(int *arr , int n){
    if(n == 1 || n == 0){
        return ;
    }
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]) ;
        }
    }
    rBubbleSort(arr , n-1) ;
}



int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]) ;

    bubbleSort(arr, n) ;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl ;

    return 0 ;
}