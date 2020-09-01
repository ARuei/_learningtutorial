#include <iostream>
#include <algorithm>

using namespace std;

int g_line, g_module;

int isOdd (int num) {

    num = abs(num%2);
    return num;
}

bool cmp (int a, int b) {

    // the remainders are not the same and sort them in ascending order
    if (a%g_module != b%g_module) return a%g_module < b%g_module;
    // the remainders are the same but not both numbers are odd or even
    else if (isOdd(a) != isOdd(b)) return isOdd(a) > isOdd(b);
    // the remainders are the same and both are odd
    else if (isOdd(a)) return a > b;
    // the remainders are the same and both are even
    else return a < b;
}

int main () {

    int counter = 20;
    while (cin >> g_line >> g_module) {

        cout << g_line << " " << g_module << endl;

        if (g_line==0) break;

        int * next = new int [g_line];
        for (int i=0; i<g_line; i++) {

            cin >> next[i]; 
        }

        sort(next, next+g_line, cmp);

        for (int i=0; i<g_line; i++) {

            cout << next[i] << endl;
        }

        delete [] next;
    }
}