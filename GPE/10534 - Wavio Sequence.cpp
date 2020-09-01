#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {

    int n;
    while (cin >> n) {

        if (cin.eof()) break;
        int * arr = new int [n+5];
        int * left_up = new int [n+5];
        int * right_down = new int [n+5];
        memset(arr, 0, sizeof(arr));
        memset(left_up, 0, sizeof(left_up));
        memset(right_down, 0, sizeof(right_down));

        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }

        vector<int> vec;
        for (int i=0; i<n; i++) {

            if (vec.empty() || vec.back()<arr[i]) {
                vec.push_back(arr[i]);
            }
            else {
                int pt = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
                vec[pt] = arr[i]; 
            }

            left_up[i] = vec.size();
        }

        vec.clear();
        for (int i=n-1; i>=0; i--) {

            if (vec.empty() || vec.back()<arr[i]) {
                vec.push_back(arr[i]);
            }
            else {
                int pt = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
                vec[pt] = arr[i]; // substitute the origin if arr[i] could be found in array
            }

            right_down[i] = vec.size();
        }

        int ans = 0;
        for (int i=0; i<n; i++) {

            ans = max(ans, min(left_up[i], right_down[i]) * 2 - 1);
        }
        
        cout << ans << endl;

        delete [] arr;
        delete [] left_up;
        delete [] right_down;
    }

    return 0;
}