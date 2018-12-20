#include <iostream>

using namespace std;

int calc_dest(int, int);

int main() {

    int case_num;
    cin >> case_num;

    int x0, y0, x1, y1;
    int cnt=0;
    while (cnt < case_num && cin >> x0 >> y0 >> x1 >> y1) {

        cnt++;
        int max_value = max(calc_dest(x1, y1), calc_dest(x0, y0));
        int min_value = min(calc_dest(x1, y1), calc_dest(x0, y0));
        int res = max_value - min_value;
        cout << "Case " << cnt << ": " << res << endl;
    }

    return 0;
}

int calc_dest(int x, int y) {

    int upper = x + y; //cout << upper << endl;
    int sum = 0;
    for (int i=0; i<=upper; i++) {

        sum+=i;
    }
    int dest = sum + x; //cout << dest << endl;

    return dest;
}
