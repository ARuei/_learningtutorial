#include <iostream>
#include <memory.h>
#include <cstdio>

using namespace std;

long long res[52];

void parsing(char input []) {

    int sign = 1, value = 0, i;
    char pos;

    for (i=1; input[i]; i++) {

        if (input[i]=='-') sign = -1;
        else if (isdigit(input[i])) {

            while (isdigit(input[i])) {
                value = value * 10 + (input[i++] - '0');
            }

            i--;
        }
        else {
            pos = input[i];
            break;
        }
    }

    value = sign * value;

    if (pos == '+') {

        parsing(input+i+1);
        
        long long tmp_1 = res[0];
        res[0] = value;

        for (int i=1; i<50; i++) {
            long long tmp_2 = res[i];
            res[i] = res[i-1] + tmp_1;
            tmp_1 = tmp_2;
        }
    }
    else if (pos == '*') {

        parsing(input+i+1);
        
        res[0] = value * res[0];

        for (int i=1; i<50; i++) {
            res[i] = res[i-1] * res[i];
        }
    }
    else {

        for (int i=0; i<50; i++) {
            res[i] = value;
        }
    }
}

int main () {

    int idx;
    char input[1024];
    while (scanf("%s %d", input, &idx)==2) {

        memset(res, 0, sizeof(res));

        parsing(input);

        for (int i=0; i<idx; i++) {
            cout << res[i];
            if (i == idx-1) {
                cout << endl;
            }
            else {
                cout << " ";
            }
        }
    }

    return 0;
}