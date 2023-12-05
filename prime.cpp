#include<iostream>
using namespace std;

// boolean function to check prime

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    bool result = isPrime(n);

    if(result){
        cout<<n<<" is prime"<<endl;
    }
    else{
        cout<<n<<" is not prime"<<endl;
    }

    return 0;
}
