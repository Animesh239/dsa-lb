// check palindrome using recursion

#include<iostream>
using namespace std ;

bool isPalindrome(string &s , int start , int end){
    if(start >= end){
        return true ;
    }
    if(s[start] != s[end]){
        return false ;
    }
    return isPalindrome(s , start + 1 , end - 1) ;
}

int main(){

    string s ;
    cin >> s ;

    bool ans = isPalindrome(s , 0 , s.length() - 1) ;

    if(ans){
        cout << "true" << endl ;
    }
    else{
        cout << "false" << endl ;
    }

    return 0 ;
}