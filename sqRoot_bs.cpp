// finding square root of a number using binary search (GIF not decimal/float)

#include <iostream>
using namespace std;

int sqRoot(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return mid;
}

int main()
{
    int n;
    cin >> n;

    cout << sqRoot(n) << endl;

    return 0;
}