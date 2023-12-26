// merge sort using recursion

#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{

    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < len1 && j < len2) 
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = left[i++];
    }

    while (j < len2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int *arr, int start, int end)
{

    // base case
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // left part sort
    mergeSort(arr, start, mid);  // time complexity: T(n/2)

    // right part sort
    mergeSort(arr, mid + 1, end);  // time complexity: T(n/2)

    // merge both part
    merge(arr, start, end);  // time complexity: O(n)
}

int main()
{

    int arr[6] = {5, 2, 7, 3, 9, 1};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// time complexity: O(nlogn)