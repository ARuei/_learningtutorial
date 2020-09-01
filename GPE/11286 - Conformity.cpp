#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main () {

    int numOfFrosh;
    while (cin >> numOfFrosh) {

        if (!numOfFrosh) break;

        int picked[5];
        char buf[20];
        map<string, int> m;
        for (int i=0; i<numOfFrosh; i++) {

            for (int j=0; j<5; j++) cin >> picked[j];

            sort(picked, picked+5);
            sprintf(buf, "%d%d%d%d%d", picked[0], picked[1], picked[2], picked[3], picked[4]);
            string str = buf;
            m[str]++;
        }

        int max = 0, winner = 0;
        map<string, int>::iterator mit;
        for (mit=m.begin(); mit!=m.end(); mit++) {

            if (mit->second > max) {
                max = mit->second;
                winner = 0;
            }

            /*
             *  Regarded as a recorder for the first time.
             *  Regarded as the increasing counter when meet up with the same max repetition.
             */
            if (mit->second == max) {

                winner += max;
            }
        } 

        cout << winner << endl;
    }

    return 0;
}