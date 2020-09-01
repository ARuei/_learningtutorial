#include <iostream>
#include <math.h>
#include <iomanip>

#define N 1000005

using namespace std;

double a[N], b[N];


int main () {

    double tmp, count = 0.0, ans = 0.0;
    for (int i=1; i<N; i++) {

        tmp = (double) i * (i + 1);
        ans += (1-ans) / tmp;
        count += log10(tmp);
        a[i] = ans;
        b[i] = count;
    }

    int num;
    while(cin >> num) {

        cout << fixed << setprecision(6) << a[num] << " ";
        cout << (int)b[num] << endl;
    }

    return 0;
}