#include <iostream>

using namespace std;

int base10(int n) {

    int counter=0;
    while (n) {

        if (n%2) {
            counter++;
        }
        n /= 2;
    }

    return counter;
}

int base16(int n) {

    int counter=0;
    while (n) {

        int temp = n%10;
        while (temp>0) {
            if (temp%2) {
                counter++;
            }
            temp /= 2;
        }
        n /= 10;
    }

    return counter;
}

int main() {

    int cases, M;

    cin >> cases;
    
    while(cases--) {

        cin >> M;
        int b1 = base10(M);
        int b2 = base16(M);

        cout << b1 << " " << b2 << endl;
    }
    return 0;
}