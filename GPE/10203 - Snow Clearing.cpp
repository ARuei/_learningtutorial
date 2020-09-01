#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;

int main () {

    int cases;
    cin >> cases;
    getchar();
    string str;
    getline(cin, str);

    while (cases--) {

        getline(cin, str);

        double dist = 0;
        double x1, x2, y1, y2;
        
        while (getline(cin, str)) {

            if (str=="") break;
            stringstream ss;
            ss.str(str);
            ss >> x1 >> y1 >> x2 >> y2;

            dist += hypot(x1-x2, y1-y2);
        }

        dist /= 1000; // to km
        double hh = dist * 2 / 20; // one lane with two direction
        int mm = (int)round(hh*60);
        cout << mm/60 << ":";
        cout << setw(2) << setfill('0') << mm%60 << endl;

        if(cases) {
            cout << endl;
        }
    }


    return 0;
}