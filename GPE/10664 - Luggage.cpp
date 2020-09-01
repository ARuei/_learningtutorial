#include <iostream>
#include <sstream>

using namespace std;

int main () {

    int cases;
    cin >> cases;
    getchar();

    string str;
    while (cases--) {

        getline(cin, str);

        stringstream ss;
        ss.str(str);
        bool dp[205] = {false};
        int w[25] = {0};

        int sum = 0;
        int idx = 0;
        while (ss >> w[idx]) {

            sum += w[idx];
            ++idx;
        }

        dp[0] = true;
        if (sum%2==0) {

            sum /= 2;
            for (int i=0; i<idx; i++) {
                for (int j=sum; j>=w[i]; j--) {

                    if (dp[j-w[i]]) {
                        dp[j] = true;
                    }
                }
            }
        }
        
        if (dp[sum]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}