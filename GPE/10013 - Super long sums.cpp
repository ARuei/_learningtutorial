#include <iostream>
#include <memory.h>

using namespace std;

const int LIMIT = 1000005;

int ans[LIMIT];

int main() {

    int cases, lenOfDigits, num_1, num_2;
    cin >> cases;
    while (cases--) {

        cin >> lenOfDigits;

        memset(ans, 0, sizeof(ans));
    
        for (int i=lenOfDigits-1; i>=0; i--) {

            cin >> num_1 >> num_2;
            ans[i] += num_1 + num_2;

            if (ans[i]>9) {
                ans[i+1] += (ans[i]/10);
                ans[i] %= 10; 
            }
        }

        for (int i=0; i<lenOfDigits; i++) {

            if (ans[i]>9) {

                ans[i+1] += (ans[i]/10);
                ans[i] %= 10; 
            }
        }

        if (ans[lenOfDigits]) lenOfDigits++;

        for (int i=lenOfDigits-1; i>=0; i--) {

            cout << ans[i];
        }

        if (cases!=0) cout << endl << endl;
        else cout << endl;
    }

    return 0;
}