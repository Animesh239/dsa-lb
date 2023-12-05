#include <iostream>
using namespace std;

// function to find max number in array
int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// function to find min number in array
int min(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{

    int n;
    cout << "Enter size of array : " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter elements of array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    char op;
    cout << "Enter operator (x for max , n for min , b for both) : " << endl;
    cin >> op;

    int maximum = max(arr, n);
    int minimum = min(arr, n);

    switch (op)
    {
    case 'x':
        cout << "Maximum number in array is : " << maximum << endl;
        break;
    case 'n':
        cout << "Minimum number in array is : " << minimum << endl;
        break;
    case 'b':
        cout << "Maximum number in array is : " << maximum << endl;
        cout << "Minimum number in array is : " << minimum << endl;
        break;
    default:
        cout << "Invalid operator" << endl;
    }

    return 0;
}