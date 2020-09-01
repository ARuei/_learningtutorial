#include <iostream>

using namespace std;

int main () {

    int cases;
    cin >> cases;

    int r, c;
    while (cases--) {

        cin >> r >> c;

        int ** grid;
        grid = new int *[r];
        for (int i=0; i<r; i++) {
            grid[i] = new int [c];
        }        

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> grid[i][j];
            }
        }

        /*
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        */

        int **dp;
        dp = new int *[r];
        for (int i=0; i<r; i++) {
            dp[i] = new int [c];
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {

                dp[i][j] += grid[i][j];
                if (i>0 && j>0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                }
                else if (i>0) {
                    dp[i][j] += dp[i-1][j];
                }
                else if (j>0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }

        cout << dp[r-1][c-1] << endl;


        for (int i=0; i<r; i++) {
            delete [] grid[i];
        }
        delete [] grid;

        for (int i=0; i<r; i++) {
            delete [] dp[i];
        }
        delete [] dp;
    }
    return 0;
}