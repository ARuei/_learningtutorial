#include <iostream>

using namespace std;

int main() {

    int v0, t;
    while (cin >> v0 >> t) {

        // v_t = v0*t + a*t -> v0 = v_t -a*t
        // s_t = v0*t + 1/2*a*t^2 -> s_2t = v0*2t + 2t^2 = 2(v_t-a*t)t+2at^2 = 2*v_0*t

        cout << 2*v0*t << endl;
    }

    return 0;
}