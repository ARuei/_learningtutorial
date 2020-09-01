#include <iostream>
#include <cmath>
#include <iomanip>

#define PI acos(-1.0)

using namespace std;

int main () {

    double s, a;
    string str;
    double arcD, chordD;
    while(cin >> s >> a >> str) {

        //cout << s << " " << a << " " << str << endl;

        double radiusS = 6440 + s;

        if (str == "min") a /= 60; // min to deg
        
        while (a>360) {

            a-=360;
        }
        if (a>180) a = 360 - a;

        arcD = 2 * PI * radiusS * a/360.0;
        chordD = radiusS * sin((a*PI)/2/180) * 2;

        //cout << fixed << setprecision(6) << arcD << " " << chordD << endl;
        printf("%.6lf %.6lf\n", arcD, chordD);
    }

    return 0;
}