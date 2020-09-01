#include <iostream>

using namespace std;

int main () {

    int n, m;
    while (cin >> n >> m) {

        if (cin.eof()) break;

        int left = 0, right = 0;
        int * arr = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (arr[i] > left) left = arr[i];
            right += arr[i];
        }

        int mid;
        while (left < right) {

            mid = (left + right) / 2;
            int sum = 0, amount = 0;

            for (int i=0; i<n; i++) {

                sum += arr[i];
                if (sum > mid) {
                    amount++;
                    sum = arr[i];
                }
                else if (sum == mid) {
                    amount++;
                    sum = 0;
                }
            }
            if (sum>0) amount++;

            if (amount > m) left = mid+1; // the original container size is too small
            else right = mid;
        }

        cout << left << endl;
    }
    

    return 0;
}