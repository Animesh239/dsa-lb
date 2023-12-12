// count all the prime numbes from 1 to n

#include<iostream>
#include<vector>
using namespace std;

// bool isPrime(int n){
//     for(int i=2;i<n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// int countPrimes(int n){
//     int count = 0;
//     for(int i=2;i<n;i++){
//         if(isPrime(i)){
//             count++;
//         }
//     }
//     return count;
// }

// this approach will give TLE

// sieve of eratosthenes

int countPrimes(int n){
    int count = 0;
    vector<bool> primes(n+1,true);

    primes[0] = primes[1] = false;

    for(int i = 2 ; i < n ; i++){
        if(primes[i]){
            count++;
            for(int j = 2*i ; j <= n ; j+=i){
                primes[j] = false;
            }
        }
    }
    return count;
}

int main(){

    int n;
    cin>>n;

    cout<<countPrimes(n)<<endl;

    return 0;
}