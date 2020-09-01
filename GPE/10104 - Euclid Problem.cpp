#include <iostream>

using namespace std;

int gcd(int a, int b, int &x, int &y) {

    if (a%b==0) {

        x = 0;
        y = 1;
        return b;
    }
    else {

        int temp_x, temp_y;
        int ret = gcd(b, a%b, temp_x, temp_y);
        x = temp_y;
        y = temp_x - a/b * temp_y;
        return ret;
    }
}

int main () {

    int A, B, D;
    int X, Y;
    while (cin >> A >> B) {

        D = gcd(A, B, X, Y);
        cout << X << " " << Y << " " << D << endl;
    }
    

    return 0;
}