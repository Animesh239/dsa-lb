#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the key : ";
    cin>>key;

    int index = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            index = i;
            break;
        }
    }

    if(index==-1){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"Key found at index "<<index<<endl;
    }

    return 0;
}
