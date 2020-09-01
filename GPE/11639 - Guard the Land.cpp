#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int main () {

    int cases;
    cin >> cases;

    int cnt = 0;
    point pt[4];
    while (cases--) {

        cin >> pt[0].x >> pt[0].y >> pt[1].x >> pt[1].y;
        cin >> pt[2].x >> pt[2].y >> pt[3].x >> pt[3].y;

        int i = max(pt[0].x, pt[2].x);
        int j = max(pt[0].y, pt[2].y);
        int k = min(pt[1].x, pt[3].x);
        int l = min(pt[1].y, pt[3].y);

        int A = (pt[1].x - pt[0].x) * (pt[1].y - pt[0].y);
        int B = (pt[3].x - pt[2].x) * (pt[3].y - pt[2].y);
        int C = (i-k) * (j-l);

        if (i>=k || j>=l) {
            cout << "Night " << ++cnt << ": 0 " << A+B << " " << 10000 - A - B << endl;
        }
        else {
            cout << "Night " << ++cnt << ": "<< C << " " << A+B-C-C << " " << 10000 - A - B + C << endl;
        }
    }
    

    return 0;
}