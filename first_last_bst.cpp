// In a sorted arr , u have to find the index of the fisrt and last occurence of a given k element.

#include <iostream>
using namespace std;

int firstLastOcc(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    int first = -1;
    int last = -1;
        int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == k){
            first = mid;
            end = mid - 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    start = 0;
    end = n - 1;
        int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == k){
            last = mid;
            start = mid + 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout << first << " " << last << endl;
    return 0;
}

void printAns(int arr[], int n, int k){
    firstLastOcc(arr, n, k);
}

int main(){
   int arr[] = {0,0,0,1,1,1,1,2,2,2,3,3,3,3,4};
   int key = 3;
   int n = sizeof(arr)/sizeof(int);

   printAns(arr, n, key);

   return 0;
}