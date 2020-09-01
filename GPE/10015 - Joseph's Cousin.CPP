#include <iostream>
#include <memory.h>

#define N 100000 // to make sure have at least 3501 prime numbers in the table

using namespace std;

int main () {

    int prime[N+5];
    bool isPrime[N+5];

    memset(isPrime, true, N+5);

    int cnt = -1;
    isPrime[0] = false, isPrime[1] = false;
    for (int i=2; i<N; i++) {

        if (isPrime[i]) {

            prime[++cnt] = i;
            for (int j=2*i; j<N; j+=i) {

                isPrime[j] = false;
            }
        }
    }

    int num;

    while (cin >> num) {

        if (!num) break;

        int ans = 0;
        for (int i=2; i<=num; i++) {

            /* 
             *  old = (new + q) % n, 
             *  where q is the mod & n is the total number in new's round 
             * 
             *  Note that, q is dynamic here of each iteration
             */
            ans = (ans + prime[num-i])%i; 
        }

        cout << ans+1 << endl; // The index offset from 0-based to 1-based
    }

    return 0;
}