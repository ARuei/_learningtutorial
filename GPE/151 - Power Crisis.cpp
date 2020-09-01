#include <iostream>

using namespace std;

int main () {

    int numOfRegions;
    while (cin >> numOfRegions) {

        if (!numOfRegions) break;

        --numOfRegions; // erase the original one

        int m, ret;
        for (m=1; m; m++) {
            ret=0;
            for (int i=1;i<=numOfRegions; i++) {

                // old = (new + q) % n
                ret = (ret+m)%i;
            }

            if (ret + 1 == 12)  {
                break;
            }
        }

        cout << m << endl;
    }

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find1Wellington (vector<int> regs) {

    vector<int>::iterator ite = find(regs.begin(), regs.end(), 12);
    return (ite!=regs.end());
}

int main() {

    int numOfRegions;

    while(cin >> numOfRegions) {

        if (!numOfRegions) break;

        int mod = 1;
        for (; mod; mod++) {

            vector<int> regions(numOfRegions);

            for (int i=0; i<numOfRegions; i++) {

                regions[i] = i;
            }

            for (int i=0; i<numOfRegions;) {

                regions.erase(regions.begin()+i);
                i += mod - 1;
                i %= regions.size();
                if (!find1Wellington(regions) || regions.size()==1)
                    break;
            }

            if (regions.size()==1 && regions[0] == 12) {

                cout << mod << endl;
                break;
            }   
        }
    }

    return 0;
}
*/


