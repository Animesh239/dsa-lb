// find_unique_in_2n+1.cpp

#include <iostream>
using namespace std;

int findUnique(int arr[], int n){
    int result = 0;
    for(int i=0;i<n;i++){
        result = result^arr[i];  // XOR operator
    }
    return result;
}


int main()
{
    int n;
    cout << "Enter the length of the array(odd) : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n ; i++)
    {
        cout << "Enter elements such that out of n elements (n-1)/2 elements are in pair and one element is alone " << i << " : ";
        cin >> arr[i];
    }

    int result = findUnique(arr, n);

    cout << "Unique element is " << result << endl;

    return 0;
}