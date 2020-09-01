#include <iostream>
#include <cstdio>

typedef long long LL;
using namespace std;

int main() {

    LL N, L, U;
    while(cin >> N >> L >> U) {

        LL ans = 0;
        for (LL i=31; i>=0; --i) {

            if (N & (1LL<<i) ){ // originally, the N's index is 1, make it 0 and test for the lower-bound

                if (ans + (1LL<<i) <= L) { // If lower than the lower-bound, add it.
                    ans += (1LL<<i);
                }
            }
            else { // originally, the N's index is 1, make it 0 and test for the upper-bound
                if (ans + (1LL<<i) <= U) { // If not exceed the upper-bound, add it.
                    ans += (1LL<<i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}