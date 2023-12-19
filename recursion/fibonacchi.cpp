// fibonacchi using recurrsion

#include<iostream>
using namespace std ;

int fibonacchi(int n){
    if(n == 0 || n == 1){
        return n ;
    }
    return fibonacchi(n - 1) + fibonacchi(n - 2) ;
}

int main(){

    int n ;
    cin >> n ;

    int ans = fibonacchi(n) ;

    cout << ans << endl ;

    return 0 ;
}