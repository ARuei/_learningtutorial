#include <iostream>
#include <stdio.h>

#define LIMIT 100

using namespace std;

int main() {

    int cases;
    cin >> cases;
    char grid [LIMIT+5][LIMIT+5] = {0};

    while (cases--) {

        int M, N, Q;    
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;

        /*
        cin.ignore();
        for (int i=0; i<M; i++) {
            cin.getline(grid[i], N+1);
            cout << grid[i] << endl;
        }
        */
        
        for (int i=0; i<M; i++) {
            scanf("%s", grid[i]);
        } 
  

        int r, c;
        while (Q--) {

            cin >> r >> c;

            int len = 1;

            bool flag;
            for (int i=0; i<=M || i<=N; i++) {

                flag = true;
                for (int j=r-i; j<=r+i; j++) {
                    for (int k=c-i; k<=c+i; k++) {
                        
                        if (j<0 || k<0 || j>=M || k>=N) {

                            flag = false;
                            break;
                        }
                        if (grid[j][k]!=grid[r][c]) {
                            flag = false;
                            break;
                        }
                    }    
                }

                if (flag) {
                    len = 2*i+1;
                }
                else {
                    break;
                }
            }

            cout << len << endl;
        }
        
    }

    return 0;
}