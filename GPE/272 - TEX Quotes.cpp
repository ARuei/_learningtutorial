#include <iostream>

using namespace std;

int main() {

    int counter = 0;

    char c;
    while (cin.get(c)) {

        if (c!='\"') {
            cout << c;
            continue;
        }
        else {

            if (counter%2==0) { 

                cout << "``";
            }
            else {

                cout << "''";
            }
            counter++;
        }
    }

    return 0;
}