#include <iostream>

#define LIMIT 100

using namespace std;

char maze[LIMIT+5][LIMIT+5] = {};
int res[LIMIT+5][LIMIT+5] = {0};


int main() {

    int row, col, cnt=0;
    while(cin >> row >> col) {

        if (row == 0 || col == 0) break;
        if (cnt>0) cout << endl;
        

        for (int i=0; i<row; i++) {
            cin >> maze[i];
        }

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {

                res[i][j] = 0;
            }
        }

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (maze[i][j]=='*') {
                    for (int ii=i-1; ii<=i+1; ii++) {
                        for (int jj=j-1; jj<=j+1; jj++) {
                            if (ii<0 || ii>=row || jj<0 || jj>=col) {
                                continue;
                            }
                            
                            ++res[ii][jj];
                        }
                    }
                }
            }
        }

        cout << "Field #" << ++cnt << ":\n";
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {

                if (maze[i][j]=='*') cout << "*";
                else cout << res[i][j];
            }
            cout << endl;
        } 
    }

    return 0;
}