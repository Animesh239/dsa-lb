#include<iostream>
using namespace std;

// function for combination logic

int combination(int n, int r){
    // write code to find nCr
    int factn = 1, factr = 1, factnr = 1;
    for(int i = 1; i <= n; i++){
        factn *= i;
    }
    for(int i = 1; i <= r; i++){
        factr *= i;
    }
    for(int i = 1; i <= n-r; i++){
        factnr *= i;
    }
    return factn/(factr*factnr);
}

// code to find nCr using functions

int main(){
    int n, r;
    cout<<"Enter n and r : ";
    cin>>n>>r;

    int result = combination(n, r);

    cout<<n<<"C"<<r<<" = "<<result<<endl;

    return 0;
}


