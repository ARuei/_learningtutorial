#include <iostream>

#define UPPERBOUND 100000

using namespace std;

int main() {

    int a, b;
    int squreTable[UPPERBOUND+1] = {};

    // create squre table first
    for (int i=1; i*i<UPPERBOUND+1; i++) {
        squreTable[i*i] = 1;
    }

    // add up with the previous item
    // note that all the initial value are 0
    for (int i=1; i<UPPERBOUND+1; i++) {
        squreTable[i] += squreTable[i-1];
    }

    while (cin >> a >> b) {

        if (a==0 || b==0) break;

        cout << squreTable[b] - squreTable[a-1] << endl;
    }

    return 0;
}