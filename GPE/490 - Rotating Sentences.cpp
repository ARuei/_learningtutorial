#include <iostream>
#include <string.h>

#define MAXNUM 100
#define MAX(x,y) ((x)>(y)?(x):(y));

using namespace std;

int main() {

    int rows = 0, cols = 0;
    char table[MAXNUM][MAXNUM+1] = {0};

    while (cin.getline(table[rows], MAXNUM+1)) { // gets(table[rows]) := X since c++14

        cols = MAX(cols, (int)strlen(table[rows]));
        ++rows;
    }

    for (int i=0; i<cols; ++i) {
        for (int j=rows-1; j>=0; --j) {
            if (table[j][i]==0) {
                cout << " ";
                continue;
            }
            else {
                cout << table[j][i];
            }
        }

        cout << endl;
    }

    return 0;
}