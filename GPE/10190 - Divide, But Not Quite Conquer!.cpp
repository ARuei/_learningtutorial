#include <iostream>

using namespace std;

bool calDivision(int n, int m) {

    bool jud;
    while (n%m==0 && n!=1) {
        
        n /= m;
    }

    n==1?jud=true:jud=false;

    return jud;
}

int main() {

    int n, m;

    bool isDivisible;
    while (cin >> n >> m) {

        if (n<2 || m<2) {
            cout << "Boring!" << endl;
            continue; 
        }
        else {
            isDivisible = calDivision(n, m);

            if (isDivisible) {

                while(n!=1) {

                    cout << n << " "; 
                    n /= m;
                }

                cout << n << endl;
            }
            else {
                cout << "Boring!" << endl;
            }
        }
    }

    return 0;
}