#include <iostream>

using namespace std;

int cal_dis(int x, int y) {

    int sum = 0;
    int upper = x+y;
    for (int i=0; i<=upper; i++) { // z steps

        sum += i;
    }

    int dis = sum + x; // the x-axis value

    return dis;
}

int main () {

    int cases, cnt=0;
    cin >> cases;
    while (cases--) {

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int res = cal_dis(x2, y2) - cal_dis(x1, y1);

        cout << "Case " << ++cnt << ": " << res << endl;
    }
}