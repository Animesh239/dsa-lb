// sorting 0,1,2 using two pointer approach

#include <iostream>
using namespace std;

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

void sortOneZeroTwo(int arr[], int n){
    int left = 0;
    int right = n - 1;
    int mid = 0;

    while(mid <= right){
        if(arr[mid] == 0){
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[right]);
            right--;
        }
    }
}

int main(){

    int arr[] = {0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};

    sortOneZeroTwo(arr, 15);
    printArray(arr, 15);

    return 0;

}
