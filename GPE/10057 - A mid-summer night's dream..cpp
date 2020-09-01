#include <iostream>
#include <algorithm>

using namespace std;

bool cmp (int a, int b) {

    return a<b;
}

int main () {

    int num;

    while (cin >> num) {

        int * arr = new int [num];
        for (int i=0;i<num;i++) {

            cin >> arr[i];
        }

        sort(arr, arr+num, cmp);

        if (num%2) { // odd

            int mid, ns = 0;
            mid = arr[num/2];
            for (int i=0; i<num; i++) {

                if (arr[i] == mid) {

                    ++ns;
                }
            }

            cout << mid << " " << ns << " " << 1 << endl;
        }
        else { //even

            int lower, upper, ns = 0, nss;
            lower = arr[num/2 - 1];
            upper = arr[num/2];

            for (int i=0; i<num; i++) {

                if ( lower<=arr[i] && arr[i]<=upper) {

                    ++ns;
                }
            }
            
            nss = upper - lower + 1;

            cout << lower << " " << ns << " " << nss << endl;
        }

        delete [] arr;
    }

    return 0;
}