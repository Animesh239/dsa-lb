// determine the no of distinct ways to climb n stairs if you can only take 1 or 2 steps at a time.

#include<iostream>
using namespace std ;

int stairs(int n){
    if(n<0){
        return 0 ;
    }
    if(n==0){
        return 1 ;
    }
    return stairs(n-1) + stairs(n-2) ;
}

int main(){

    int n ;
    cin >> n ;

    int ans = stairs(n) ;

    cout << ans << endl ;

    return 0 ;
}

