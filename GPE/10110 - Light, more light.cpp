#include <iostream>
#include <cmath>

using namespace std;

int main() {

    unsigned num;

    while (cin >> num) {

        if (num==0) break;

        unsigned root = sqrt(num);
        if (root*root == num) cout << "yes" << endl;
        else cout << "no" << endl; 
    }

    return 0;

}