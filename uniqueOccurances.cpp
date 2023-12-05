#include <iostream>
using namespace std;

bool uniqueOccurances(int arr[], int n)
{
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (count[i] == count[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (uniqueOccurances(arr, n))
    {
        cout << "All elements have unique occurances" << endl;
    }
    else
    {
        cout << "All elements do not have unique occurances" << endl;
    }

    return 0;
}

// The function uniqueOccurances in the provided C++ code is designed to check if all the elements in an array have unique occurrences. It takes two parameters: an integer array arr[] and an integer n which represents the size of the array.

// The function starts by declaring an integer array count[] of size n. This array will be used to store the count of occurrences of each element in the arr[]. The first for loop initializes all elements of count[] to 1. This is done under the assumption that each element in arr[] occurs at least once.

// The second nested for loop is used to count the occurrences of each element in arr[]. For each element in arr[], it checks all the elements to its right. If it finds an element that is equal to the current element, it increments the corresponding count in count[].

// The third nested for loop checks if any two elements in count[] are equal. If it finds two elements that have the same count, it means that there are two different elements in arr[] that occur the same number of times. In this case, it returns false.

// If the function goes through all the elements in count[] without finding any two elements with the same count, it returns true. This means that all elements in arr[] have unique occurrences.

// This function has a time complexity of O(n^2) due to the nested for loops. It could be optimized by using a hash map to store the count of occurrences, which would reduce the time complexity to O(n).
