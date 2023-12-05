#include<iostream>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    int result = fib(n);

    cout<<"Fibonacchi of "<<n<<" is "<<result<<endl;

    return 0;
}   

// output:
// Enter n : 10
// Fibonacchi of 10 is 55
