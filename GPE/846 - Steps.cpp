#include <iostream>

typedef long long LL;

using namespace std;

int main () {

    int cases;

    cin >> cases;

    LL lower, upper;
    while(cases--){

        cin >> lower >> upper;
        LL diff = upper - lower;

        LL len = 0, sum = 0, steps = 0;
        while (true) {

            len++;
            if (sum + 2*len > diff) break;

            steps += 2; // on both sides
            sum += 2*len;
        }

        if (sum + len < diff) steps += 2; // insert next len in the middle and check
        else if (sum != diff) ++steps; // equal or greater than diff, then only need one step more 

        cout << steps << endl;
    }

    return 0;
}