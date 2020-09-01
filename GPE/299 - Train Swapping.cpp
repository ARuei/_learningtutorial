#include <iostream>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    while (cases--) {

        int length;
        cin >> length;
        int * arr = new int [length+5]{};
        for (int i=0; i<length; i++) {

            cin >> arr[i];
        }

        int cnt = 0, temp;
        for (int i=0; i<length-1; i++) {
            for (int j=0; j<(length-i-1); j++) {

                if (arr[j]>arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    ++cnt;
                }
            }
        }

        cout << "Optimal train swapping takes " << cnt << " swaps.\n";

        delete [] arr;
    }

    return 0;
}