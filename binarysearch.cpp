// binary search

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

void printindex(int arr[], int n, int key)
{
    int index = binarySearch(arr, n, key);
    cout << "The index of " << key << " is " << index << endl;
}

int main()
{

    int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[5] = {1, 3, 5, 7, 9};

    printindex(even, 6, 6);
    printindex(odd, 5, 5);
}