// selection sort using recursion

#include <iostream>
using namespace std ;

void rSelectionSort(int *arr , int n){
    if(n == 0 || n == 1){
        return ;
    }

    // swap the first element with the mininmum element in the array
    int min = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < arr[min]){
            min = i ;
        }
    }
    swap(arr[0] , arr[min]) ;

    // sort the rest of the array
    rSelectionSort(arr+1 , n-1) ;
}

int main(){

    int arr[6] = { 0 , 15 , 1 , 7 , 10 , 9 } ;
    int n = 6 ;

    rSelectionSort(arr , n) ;

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }

    return 0 ;
}

