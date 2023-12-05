#include<iostream>
using namespace std;

// swap alternate elements of an array
void swapAlt(int arr[], int n){
    for(int i=0;i<n-1;i+=2){
        swap(arr[i],arr[i+1]);
    }
}

int main(){
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    swapAlt(arr,n);

    cout<<"Array after swapping alternate elements is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}