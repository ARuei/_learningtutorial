#include <iostream>
#include <memory.h>

#define N 1000005
#define INF 0x3f3f3f3f3f

using namespace std;

bool isPrime[10*N];
int prime[N] = {0};

int main () {

    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = 0; isPrime[1] = 0;

    int cnt = 0;
    for (int i=2; i<N; i++) {

        if (isPrime[i]) {

            prime[cnt++] = i;
            for (int j=i+i; j<N; j+=i) {
                isPrime[j] = 0;
            }
        }
    }

    long long L, U;
    while (cin >> L >> U) {

        memset(isPrime, true, sizeof(isPrime));

        for (int i=0; i<cnt; i++) {
            for (long long j=(L/prime[i] + (L%prime[i]!=0))*prime[i]; j<=U; j+=prime[i]) {

                if (j/prime[i]!=1) {
                    isPrime[j-L] = 0;
                }
            }
        }

        long long minL, minR, maxL, maxR;
        long long minDist = INF, maxDist = 0;
        int pre = -1, isFound = 0;

        for (long long i=L; i<=U; i++) {

            if (!isPrime[i-L] || i==1) continue; /* The below i must be prime */
            

            if (pre!=-1) {

                if (i - pre < minDist) {

                    minL = pre;
                    minR = i;
                    minDist = i - pre;
                }
                if (i - pre > maxDist) {

                    maxL = pre;
                    maxR = i;
                    maxDist = i -pre;
                }

                isFound = 1;
            }

            pre = i;
        }

        if (isFound) {
            cout << minL << "," << minR << " are closest, ";
            cout << maxL << "," << maxR << " are most distant.\n";
        }
        else if (!isFound) {

            cout << "There are no adjacent primes.\n";
        }
    }

    return 0;
}


/*
#include <iostream>
#include <climits>
#include <memory.h>

#define N 100005
#define INF 0x3f3f3f3f3f

using namespace std;

int main () {

    int isPrime[10 * N] = {0};
    int primes[N] = {0};

    int idx = 0;
    for (int i=2; i<N; i++) {

        if (!isPrime[i]) {

            primes[idx++] = i;
            for(int j=i+i; j<N; j+=i) {
                isPrime[j] = 1;
            }    
        }
    }

    long long L, U;
    while (cin >> L >> U) {

        memset(isPrime, 0, sizeof(isPrime));
        for (int i=0; i<idx; i++) {
            for (long long j = (L/primes[i]+(L%primes[i]!=0))*primes[i]; j<=U; j+=primes[i]) {

                if (j/primes[i]!=1) {
                    isPrime[j-L] = 1;
                }
            }
        }

        long long minL, minR, maxL, maxR;
        long long dis_min = INF, dis_max = 0;
        int pre = -1, isFound = 1;
        for (long long i=L; i<=U; i++) {

            if (isPrime[i-L] || i==1) continue;

            if (pre!=-1) {

                if (i - pre < dis_min ) {

                    minL = pre;
                    minR = i;
                    dis_min = i - pre;
                }
                if (i - pre > dis_max) {

                    maxL= pre;
                    maxR = i;
                    dis_max = i - pre;
                }

                isFound = 0;
            }

            pre = i;
        }

        if (!isFound) {

            cout << minL << "," << minR << " are closest, ";
            cout << maxL << "," << maxR << " are most distant.\n";
        }
        else if (isFound) {

            cout << "There are no adjacent primes.\n";
        }
    }


    return 0;
}
*/