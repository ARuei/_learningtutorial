#include <iostream>

#define N 100000

using namespace std;

int sumOfDigits(int num) {

    int ret = 0;
    while (num) {

        ret += num%10;
        num /= 10;
    }

    return ret;
}

int main () {

    int cnt = 0;
    int isPrime[N] = {0};
    int primeTable[N] = {0};

    isPrime[0] = 1, isPrime[1] = 1;
    for (int i=2; i<N; i++) {

        if (!isPrime[i]) {

            primeTable[cnt++] = i;

            for (int j=i+i; j<N; j+=i) {
                isPrime[j] = 1;
            }
        }
    }

    int cases;
    cin >> cases;
    while(cases--) {

        int answer;
        cin >> answer;
        int sum = 0, t_sum = -1;
        while (t_sum != sum) {

            int n = ++answer;
            
            if (n<N && !isPrime[n]) {
                continue;
            }

            t_sum = 0;
            sum = sumOfDigits(answer);

            for (int i=0; i<cnt && primeTable[i]*primeTable[i]<=n; i++) {

                if (!(n%primeTable[i])) {

                    int prime = sumOfDigits(primeTable[i]);
                    while (!(n%primeTable[i])) {

                        t_sum += prime;
                        n/=primeTable[i];
                    }
                }
            }

            if (answer == n) { // n is a prime number
                continue;
            }

            if (n!=1) { // n is a prime factor
                t_sum += sumOfDigits(n);
            }
        }

        cout << answer << endl;
    }

    return 0;
}
