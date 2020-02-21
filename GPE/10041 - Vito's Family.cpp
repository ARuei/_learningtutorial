#include <iostream>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;

int calc_dis(int [], int);

int main (int argc, char** argv) {

    int cases, neighbors, street_num;
    int loc[500];

    cin >> cases;

    int res;
    while (cases--) {

        memset(loc, '0', sizeof(loc));

        cin >> neighbors;
        for (int i=0; i < neighbors; i++) {

            cin >> loc[i];
        }

        sort(loc, loc+neighbors);

        // not especially consider the odd and even cases
        // cuz the median after sorting will be picked anyway
        res = calc_dis(loc, neighbors);

        cout << res << endl;
    }

    return 0;
}

int calc_dis(int loc[], int neighbors) {

    int middle = loc[(neighbors/2)];
    int sum = 0;
    for (int i=0; i < neighbors; i++) {

        sum += abs(middle - loc[i]);
    }

    return sum;
}