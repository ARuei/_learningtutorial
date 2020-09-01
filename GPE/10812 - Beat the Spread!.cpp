#include <iostream>

using namespace std;


int main() {

    int n;
    cin >> n;

    long long int s, d;
    while (n--) {

        cin >> s >> d;

        if (s<d) {
            cout << "impossible" << endl;
        }
        else if (s<0 || d<0) {
            cout << "impossible" << endl;
        }
        else {

            long long int a, b;
            if ((s+d)%2!=0) {
                cout << "impossible" << endl;
                continue;
            }
            a = (s+d)/2;
            b = (s-d)/2;

            cout << a << " " << b << endl;

        }
    }

    return 0;
}