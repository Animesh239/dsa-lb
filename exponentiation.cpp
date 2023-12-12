// modular exponentiation

#include <iostream>
using namespace std;

long long int power(long long int x, long long int n, long long int m)
{
    long long int ans = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            x = (x * x) % m;
            n = n / 2;
        }
        else
        {
            ans = (ans * x) % m;
            n = n - 1;
        }
    }
    return ans;
}

int main()
{
    long long int x, n, m;
    cin >> x >> n >> m;

    cout << power(x, n, m) << endl;

    return 0;
}
