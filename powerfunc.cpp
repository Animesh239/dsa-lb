#include <iostream>
using namespace std;

int power(int a, int b)
{
    int result = 1;
    for (int i = 0; i <= b; i++)
    {
        result *= a;
    }
    return result;
}

int main()
{

    int a, b;
    cout << "Enter a and b : " << endl;
    cin >> a >> b;

    int result = power(a, b);

    cout << "a^b = " << result << endl;

    return 0;
}