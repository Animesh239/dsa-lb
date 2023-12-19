// binary search using recursion

#include<iostream>
using namespace std ;

bool binarySearch(int *arr , int start , int end , int x){
    if(start > end){
        return false ;
    }
    int mid = (start + end) / 2 ;
    if(arr[mid] == x){
        return true ;
    }
    else if(arr[mid] > x){
        return binarySearch(arr , start , mid - 1 , x) ;
    }
    else{
        return binarySearch(arr , mid + 1 , end , x) ;
    }
}

// to return the index of the element
int binarySearch2(int *arr , int start , int end , int x){
    if(start > end){
        return -1 ;
    }
    int mid = (start + end) / 2 ;
    if(arr[mid] == x){
        return mid ;
    }
    else if(arr[mid] > x){
        return binarySearch2(arr , start , mid - 1 , x) ;
    }
    else{
        return binarySearch2(arr , mid + 1 , end , x) ;
    }
}

int main(){

    int n ;
    cin >> n ;

    int *arr = new int[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    int x ;
    cin >> x ;

    bool ans = binarySearch(arr , 0 , n - 1 , x) ;

    if(ans){
        cout << "true" << endl ;
    }
    else{
        cout << "false" << endl ;
    }

    int ans2 = binarySearch2(arr , 0 , n - 1 , x) ;

    cout << ans2 << endl ;

    delete [] arr ;

    return 0 ;
}