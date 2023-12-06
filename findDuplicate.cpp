#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n){
    // using XOR
    int res = arr[0];
    for(int i = 1; i < n; i++){
        res = res ^ i ^ arr[i];
    }
    return res;

    // using sum
    // int sum = 0;
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    // }
    // return sum - (n * (n - 1) / 2);

}

int main(){
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int duplicate = findDuplicate(arr, n);

    return 0;
}