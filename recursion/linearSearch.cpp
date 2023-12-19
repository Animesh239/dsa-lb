// linear search using recursion

#include<iostream>
using namespace std ;

int linearSearch(int *arr , int n , int x){
    if(n == 0){
        return -1 ;
    }
    if(arr[0] == x){
        return 0 ;
    }
    int smallAns = linearSearch(arr + 1 , n - 1 , x) ;
    if(smallAns == -1){
        return -1 ;
    }
    return smallAns + 1 ;  // +1 because we are returning the index of the element
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

    int ans = linearSearch(arr , n , x) ;

    cout << ans << endl ;

    delete [] arr ;

    return 0 ;
}