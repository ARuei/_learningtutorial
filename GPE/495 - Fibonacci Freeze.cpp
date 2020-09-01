#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int fib[5001][500] = {0};
    fib[1][0] = 1;

    for (int i=2; i<5001; i++) {
        for (int j=0; j<500; j++) {

            fib[i][j] += fib[i-1][j] + fib[i-2][j];
            if (fib[i][j]>=1000) {

                fib[i][j+1] += fib[i][j]/1000;
                fib[i][j] %= 1000;
            }
        }
    }



    int num;

    while (cin >> num) {

        if (cin.eof()) break;
        
        cout << "The Fibonacci number for " << num
            << " is ";

        if (num==0) {

            cout << "0\n";
        }
        else {
            int end = 500;
            while(!fib[num][--end]);
            cout << fib[num][end--];
            for (; end>=0; end--) {
                cout << setw(3) << setfill('0') << fib[num][end];
            }

            cout << endl;

        }
    }

    return 0;
}