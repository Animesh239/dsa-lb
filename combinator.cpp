#include <iostream>
using namespace std;

// function to calculate factorial
int factorial(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int combination(int n, int r)
{
    // write code to find nCr
    int factn = factorial(n);
    int factr = factorial(r);
    int factnr = factorial(n - r);
    return factn / (factr * factnr);
}

// code to find nCr using functions

int main()
{
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    int result = combination(n, r);

    cout << n << "C" << r << " = " << result << endl;

    return 0;
}
