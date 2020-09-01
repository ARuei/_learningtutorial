#include <iostream>

#define row 1005
#define col 5005

using namespace std;

int fib[row][col];

int main () {

    fib[0][0] = 1;
    fib[1][0] = 1;

    for (int i=2; i<row; i++) {
        for (int j=0; j<col; j++) {

            fib[i][j] = fib[i-1][j] * i; 
        }

        for (int j=0; j<col; j++) {
            while (fib[i][j] >= 10) {
                fib[i][j+1] += fib[i][j] / 10;
                fib[i][j] %= 10;
            }
        }
    }

    int num;
    while (cin >> num) {

        int idx = col;
        while(!fib[num][--idx]);

        int sum = 0;
        for (; idx>=0; idx--) {

            sum += fib[num][idx];
        }

        cout << sum << endl;
    }

    return 0;
}

/*
#include <iostream>

using namespace std;

int main() {

    const int row = 1005;
    const int col = 5005;

    int factorial[row][col] = {0};

    factorial[0][0] = 1;
    factorial[1][0] = 1;

    for (int i=2; i<row; i++) {

        for (int j=0; j<col; j++) {

            factorial[i][j] = factorial[i-1][j] * i;
        }

        for (int j=0; j<col; j++) {

            if (factorial[i][j]>=10) {

                factorial[i][j+1] += factorial[i][j]/10;
                factorial[i][j] %= 10;
            }
        }
    }

    int num;
    while (cin>>num) {

        int idx = col, sum = 0;
        while (!factorial[num][--idx]);
        for (; idx>=0; --idx) {

            sum += factorial[num][idx];
        }
        cout << sum << endl;
    }

    return 0;
}
*/