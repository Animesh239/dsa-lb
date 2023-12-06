// sorting 0 ,1 using two pointer approach

#include <iostream>
using namespace std;

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

void sortOneZero(int arr[], int n){
    int left = 0;
    int right = n - 1;

    while(left < right){
        while(arr[left] == 0 && left < right){
            left++;
        }
        while(arr[right] == 1 && left < right){
            right--;
        }
        if(arr[left] == 1 && arr[right] == 0){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main(){

    int arr[] = {0,1,0,1,1,0,1,0,1,0,1,0,1,0,1};

    sortOneZero(arr, 15);
    printArray(arr, 15);

    return 0;

}