#include <iostream>
#include <string.h>

using namespace std;

int main () {

    char num[1001];
    while (cin>>num) {

        long long sum [2] = {0,0};
        if (strlen(num)==1 && num[0]=='0') {
            break;
        }

        for (int i=0; i<strlen(num); i++) {

            if (i%2) { // odd
                sum[0] += num[i] - '0';
            }
            else {
                sum[1] += num[i] - '0';
            }
        }

        if ( (abs(sum[0]-sum[1]))%11==0) {

            cout << num << " is a multiple of 11." << endl;
        }
        else {

            cout << num << " is not a multiple of 11." << endl;
        }
    }

    return 0;
}