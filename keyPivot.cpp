// find a index of the key elememt in the sorted and rotated array.

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
            // cout << "1" << endl;
            start = mid + 1;
        }
        else
        {
            // cout << "2" << endl;
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    // cout << "3" << endl;
    return start;
}

int keyIndex(int arr[], int n, int key)
{
    int pivot = pivotIndex(arr, n);
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    if (key >= arr[0])
    {
        start = 0;
        end = pivot;
    }
    else
    {
        start = pivot + 1;
        end = n - 1;
    }

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << keyIndex(arr, n, 9) << endl;

    return 0;
}

// time complexity: O(logn)