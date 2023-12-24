// quick sort using recursion

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

     int pivot = arr[start];

    // putting the number at right place
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (pivot > arr[i])
        {
            count++;
        }
    }
    int p = start + count;   // index of pivot
    swap(arr[start], arr[p]);

    // sorting left and right part
    int i = start, j = end;
    while (i < p && p < j)
    {
        if (arr[i] < arr[p])
        {
            i++;
        }
        else if (arr[j] >= arr[p])
        {
            j--;
        }
        else
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return p;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[7] = {9, 9, 9, 8, 2, 3, -6};
    int n = 7;

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
