#include <iostream>
#include <memory.h>
#define N 10005

using namespace std;

int main () {

    bool isPrime[N];
    memset(isPrime, true, sizeof(isPrime));
    /*
    for (int i=0; i<N; i++) {
        isPrime[i] = 1;
    }
    */

    int prime[N] = {0};

    isPrime[0] = 0, isPrime[1] = 0;

    int cnt = 0;
    for (int i=2; i<N; i++) {
        
        if (isPrime[i]) {
            prime[cnt++] = i;

            for (int j=i+i; j<N; j+=i) {
                isPrime[j] = 0;
            }
        }
    }

    int num;

    while (cin >> num) {

        if (!num) break;

        int left = 0, right = 0, sum = 0, ans = 0;
        for (; right < cnt; right++) {
            sum += prime[right];

            while (sum > num) {
                sum -= prime[left++];
            }

            if (sum == num) {
                ++ans;
            }
        }

        cout << ans << endl;
    }


    return 0;
}