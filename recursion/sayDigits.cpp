// say digits

#include <iostream>
using namespace std;

void sayDigits(int n){
    string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"} ;
    if(n == 0){
        return;
    }
    sayDigits(n / 10);
    cout << words[n % 10] << " ";
}

int main(){

    int n ;
    cin >> n ;

    sayDigits(n) ;

    return 0 ;
} 