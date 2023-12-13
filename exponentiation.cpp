// modular exponentiation

#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    int answer = 1;
    while (n > 0) {
		// If bitwise and of 'N' with 1 is 1 then multiply answer with 'X'.
		if (n & 1)  {
			answer = (1LL * answer * x) % m;
		}
		// Do modular squaring of 'X'.
		x = (1LL * x * x ) % m;

		// Right shift 'N' by 1 bit for next iteration. 
		n >>= 1;
	}
    return answer;
}

int main()
{
    long long int x, n, m;
    cin >> x >> n >> m;

    cout << modularExponentiation(x, n, m) << endl;

    return 0;
}
