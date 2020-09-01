#include <iostream>

using namespace std;

int main() {

    int dp[40] = {0,1};
    for (int i=2;i<40;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int cases;
    cin >> cases;
    while(cases--) {

        int num;
        bool start = false;
        cin >> num;
        cout << num << " = ";

        for (int i=39; i>=2; i--) {

            if (num>=dp[i]) {
                cout << "1";
                num -= dp[i];
                start = true;
            }
            else if (start) {
                cout << "0";
            }
        }
        
        cout << " (fib)" << endl;
    }

    return 0;
}