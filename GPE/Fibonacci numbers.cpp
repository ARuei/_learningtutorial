#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

unsigned long long fnum(int);

int main() {

    int input_index, cnt=0;
    unsigned long long res;

    while (cin >> input_index) {

        cnt++;
        int n = input_index;

        res = fnum(n);
        //cout << res << endl;
        if (res < UINT_MAX) {

            if (res == 0) {

                cout << "case " << cnt << ":\n" << "0\n" << endl;
            }
            else if (res == 1) {

                cout << "case " << cnt << ":\n" << "1\n" << endl;
            }
            else {

                cout << "case " << cnt << ":\n" << res << "\n" << endl;
            }
        }
        else {

            cout << "case " << cnt << ":\n" << "overflow\n" << endl;
        }
    }

    return 0;
}

unsigned long long fnum(int n) {

    long long int DP[51] = {0,1,1};
    for (int i=2;i<=50;i++) {

        DP[i] = DP[i-1] + DP[i-2];
    }

    return DP[n];

    /*
    if (n==0) return 0;
    if (n==1 || n==2) return 1;
    if (n==3) return 2;

    unsigned long long fib;
    for (int i=1;i<=n;i++) {

        fib = (pow((1+sqrt(5))/2,i)-pow((1-sqrt(5))/2,i))/sqrt(5);
    }

    return fib;*/
}
