#include <iostream>
#include <iomanip>

using namespace std;

int pow(int x, int y) {

    int tmp = 1;

    while(y--) {

        tmp *= x;
    }

    return tmp;
}

int main () {

    int digits;

    while(cin >> digits) {

        for(int i=0; i*i<pow(10, digits); i++) {

            int squre = i*i, first, second;
            first = squre/(pow(10, digits/2));
            second = squre%(pow(10, digits/2));

            if (pow(first+second, 2) == squre) {

                cout << setfill('0') << setw(digits/2) << first;
                cout << setfill('0') << setw(digits/2) << second;
                cout << endl;    
            }
        }
    }

    return 0;
}