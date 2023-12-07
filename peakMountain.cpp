// the array is in the form of a mountain. You have to find the peak element in the array.

#include <iostream>
using namespace std;

int peakMountain(int arr[], int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while(start <= end){
        mid = start + (end - start)/2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6};
    int n = sizeof(arr)/sizeof(int);

    cout << peakMountain(arr, n) << endl;

    return 0;
}

// Time Complexity : O(logn)