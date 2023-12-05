#include<iostream>
using namespace std;

int checkEvenOdd(int n){
    if(n%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    int result = checkEvenOdd(n);

    if(result==1){
        cout<<n<<" is even"<<endl;
    }
    else{
        cout<<n<<" is odd"<<endl;
    }

    return 0;
}