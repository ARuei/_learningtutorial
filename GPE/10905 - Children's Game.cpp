#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (string str1, string str2) {

    if (str1+str2 > str2+str1) return true;
    return false;
}

int main () {

    int len;
    while (cin >> len) {

        if (!len) break;

        string * numbers = new string[len];

        for (int i=0; i<len; i++) {

            cin >> numbers[i];
        }

        sort(numbers, numbers+len, cmp);

        for (int i=0; i<len; i++) {

            cout << numbers[i];
        }
        cout << endl;

        delete [] numbers;
    }

    return 0;
}