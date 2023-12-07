// find the index of the pivot element in a sorted and rotated array.

#include <iostream>
using namespace std;

int pivotIndex(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            cout << "1" << endl;
            start = mid + 1;
        }
        else
        {
            cout << "2" << endl;
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    cout << "3" << endl;
    return start;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << pivotIndex(arr, n) << endl;

    return 0;
}