// There is an unsorted arr of N elements each representing the position of a stall. There are K no. of cows that need to be placed in the stalls. Find the largest minimum distance between the cows.

#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid)
{
    int cowCount = 1;
    int pos = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            cowCount++;
            pos = arr[i];
            if (cowCount == k)
            {
                return true;
            }
        }
    }
    return false;
}

int findLargestMinDistance(int arr[], int n, int k)
{
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (isPossible(arr, n, k, mid))
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[6] = {0, 3, 4, 7, 10, 9};
    int n = 6;
    int k = 4;

    cout << findLargestMinDistance(arr, n, k) << endl;
}
