#include <iostream>
#include <memory.h>

using namespace std;

/* dp[i][j] := the front i elements divided by K with remainder j */
bool dp[10005][105];


int main () {

    int cases;
    cin >> cases;

    int N, K;
    while (cases--) {

        cin >> N >> K;

        int * arr  = new int [N];
        for (int i=0; i<N; i++) {
            cin >> arr[i];
        }

        for (int i=0; i<N; i++) {
            arr[i] = abs(arr[i]) % K; 
        }

        memset(dp, 0, sizeof(dp));


        dp[0][0] = 1;
        for (int i=0; i<N; i++) {
            for (int j=0; j<K; j++) {

                if (dp[i][j]) {
                    dp[i+1][(j+K+arr[i])%K] = 1;
                    dp[i+1][(j+K-arr[i])%K] = 1;
                }
            }
        }

        if (dp[N][0]) { 
            cout << "Divisible" << endl; 
        }
        else {
            cout << "Not divisible" << endl;
        }

        delete [] arr;
    }
    

    return 0;
}