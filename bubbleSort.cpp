// bubble sort with given arr , n ;

#include <iostream>
using namespace std;

// void bubbleSort(int arr[] , int n){
//     for(int i=0; i< n; i++){
//         for(int j = i ; j <n ; j++){
//             if(arr[j+1] < arr[j]){
//                 swap(arr[j], arr[j+1]) ;
//             }
//         }
//     }
// }

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) // if no swapping is done in the previous iteration , then the array is already sorted . It is done to optimize the code .
        {
            break;
        }
    }
}

int main()
{
    int arr[6] = {0, 15, 1, 7, 10, 9};
    int n = 6;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity : O(n^2)
