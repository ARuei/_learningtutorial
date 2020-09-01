#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

int main() {

    const int LIMIT = 50000;

    bool primeLabel[LIMIT];
    int primeTable[LIMIT];

    memset(primeLabel, true, sizeof(primeLabel));
    memset(primeTable, 0, sizeof(primeLabel));

    int idx = 0;
    for (int i=2; i<LIMIT; i++) {

        if (primeLabel[i]==true) {

            primeTable[idx] = i;
            ++idx;

            for (int j=i+i; j<LIMIT; j+=i) {

                primeLabel[j]=false;
            }
        }
    }

    int num;
    while (cin >> num) {

        if (num==0) break;

        int ans = num;
        for (int i=0; primeTable[i]*primeTable[i]<=num; i++) {

            if (num%primeTable[i]==0) {

                ans = ans/primeTable[i] * (primeTable[i]-1);
            }

            while (num%primeTable[i]==0) {

                num /= primeTable[i];
            }
        }

        if (num!=1) {

            ans = ans/num * (num-1);
        }

        cout << ans << endl;
    }

    return 0;
}