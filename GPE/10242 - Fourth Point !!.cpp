#include <iostream>
#include <iomanip>

using namespace std;

struct Point {

    double x;
    double y;
};

bool check_dup (Point p1, Point p2) {

    if (p1.x==p2.x && p1.y == p2.y) {
        return true;
    }
    else return false;
}

int main() {

    Point pt[4];

    while (cin >> pt[0].x >> pt[0].y >> pt[1].x >> pt[1].y >>
        pt[2].x >> pt[2].y >> pt[3].x >> pt[3].y) {

        double x_s = 0, y_s = 0;
        for (int i=0; i<4; i++) {

            x_s += pt[i].x;
            y_s += pt[i].y;
        }

        for(int i=0; i<4; i++) {
            for (int j=i+1; j<4; j++) {
                if (check_dup(pt[i], pt[j])) {
                    
                    x_s -= 3*pt[i].x;
                    y_s -= 3*pt[j].y;
                    cout << fixed << setprecision(3) << x_s << " " << y_s << endl;

                    break;
                }
            }
        }
    } 

    return 0;
}