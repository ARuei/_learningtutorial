#include <iostream>

using namespace std;

int main () {

    int fib[105][2000] = {0};

    fib[1][0] = 1, fib[2][0] = 2;
    for (int i=3; i<105; i++) {
        for (int j=0; j<2000; j++) {
            
            fib[i][j] += fib[i-1][j] + fib[i-2][j]; 

            if (fib[i][j]>=10) {
                fib[i][j+1] += fib[i][j] / 10;
                fib[i][j] %= 10;
            }
        }
    }


    int num;

    while (cin >> num) {

        int idx = 2000;
        while(!fib[num][--idx]);

        for (; idx>=0; idx--) {

            cout << fib[num][idx];
        }
        cout << endl;
    }

    return 0;
}