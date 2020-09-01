#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> set) {

    for (int d=set.size()-1; d>=0; d--) {
        for (int a=0; a<set.size(); a++) {
            for (int b=a+1; b<set.size(); b++) {
                for (int c=b+1; c<set.size(); c++) {

                    if (set[d] == set[a] + set[b] + set[c]) {

                        if (a!=d && b!=d && c!=d) {
                            return set[d];
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main () {

    int numOfSet;

    while (cin >> numOfSet) {

        if (!numOfSet) break;

        vector<int> set(numOfSet);

        for (int i=0; i<numOfSet; i++) {
            cin >> set[i];
        }

        sort(set.begin(), set.end());

        int d = solve(set);
        if (d == -1) { 
            cout << "no solution" << endl;
        }
        else {

            cout << d << "\n";
        }

    }

    return 0;
}