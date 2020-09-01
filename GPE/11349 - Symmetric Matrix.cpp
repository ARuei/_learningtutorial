#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int cases, cnt=0;
    cin >> cases;
    while(cases--) {

        int n;
        scanf(" N = %d", &n);
        
        long long int * mat = new long long int [n*n];

        for (int i=0; i<n*n; i++) {

            cin >> mat[i];
        }

        /*        
        for (int i=0; i<n*n; i++) {

            cout << mat[i] << " ";
        }
        cout << endl;
        */

        bool isSymmetric = true;
        int end = n*n-1;
        for (int i=0; i<n*n; i++) {

            if (i>end || !isSymmetric) break;

            if (mat[i] < 0 || mat[i] != mat[end-i]) isSymmetric = false;
        }

        isSymmetric == true ? printf("Test #%d: Symmetric.\n", ++cnt) : printf("Test #%d: Non-symmetric.\n", ++cnt) ;
    }
}