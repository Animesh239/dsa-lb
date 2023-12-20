// calculate power using recursion

#include<iostream>
using namespace std ;

int power(int x , int n){
    // base case
    if(n == 0){
        return 1 ;

    // optimisation  // the no of iterations will be reduced to half
    }else if(n % 2 == 0){
        int smallAns = power(x , n / 2) ;
        return smallAns * smallAns ;
    }else{
        int smallAns = power(x , n / 2) ;
        return x * smallAns * smallAns ;
    }

}

int main(){

    int x , n ;
    cin >> x >> n ;

    int ans = power(x , n) ;

    cout << ans << endl ;

    return 0 ;
}