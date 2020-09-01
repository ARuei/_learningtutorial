#include <iostream>
#include <memory.h>

using namespace std;

int dp[27][27][352]; /* letter, length, sum*/

int main () {

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i=1; i<=26; i++) {
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=351; k++) {

                dp[i][j][k] = dp[i-1][j][k];
                if (j>0 && k>=i) {
                    dp[i][j][k] += dp[i-1][j-1][k-i];
                }
            }
        }
    }    

    int L, S, cnt = 0;
    while (cin >> L >> S) {

        if (!L && !S) break;
        if (L>26 || S >351) {
            cout << "Case " << ++cnt << ": " << "0" << endl;
        }
        else {
            cout << "Case " << ++cnt << ": " << dp[26][L][S] << endl;
        }
    }

    return 0;
}