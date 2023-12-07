// finding square root of a number using binary search along with the decimals

#include <iostream>
using namespace std;

int sqRoot(int n)
{
    long long int s = 0;
    long long int e = n;
    long long int mid = s + (e - s) / 2;

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

double sqRootDecimals(int n, int precision, int sqRoot)
{
    double factor = 1.0 / 10.0; // Start with the smallest decimal place
    double ans = sqRoot;

    for (int i = 0; i < precision; i++)
    {
        while ((ans + factor) * (ans + factor) <= n)
        {
            ans += factor;
        }
        factor /= 10.0;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    long long int result = sqRoot(n);
    cout << sqRootDecimals(n, 3, result) << endl;

    return 0;
}