#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

int a[52];

void parse(char s[]) {

    int sign = 1, m = 0, i;
    char pos;
    for (i=1; s[i]; i++) {

        if (s[i]=='-') sign = -1;
        else if (isdigit(s[i])) {

            while (isdigit(s[i])) {
                m = m * 10 + (s[i++] - '0');
            }
            i--;
        }
        else {
            pos = s[i];
            break;
        }
    }

    m = m * sign;

    if (pos == '+') {

        parse(s + i + 1);
        long long tmp1 = a[0];
        a[0] = m;
        for (int i=1; i<50;i++) {
            long long tmp2 = a[i];
            a[i] = a[i-1] + tmp1;
            tmp1 = tmp2;
        }
    }
    else if (pos =='*') {
        parse(s + i + 1);
        a[0] = a[0] * m;
        for (int i=1; i<50;i++) {
            a[i] = a[i-1] * a[i];
        }
    }
    else {
        for (int i=0;i<50;i++) {
            a[i] = m;
        }
    }
}

int main () {

    char s[1024];
    int num;
    while (scanf("%s %d", s, &num)==2) {

        memset(a, 0, sizeof(a));
        parse(s);

        for (int i=0; i<num; i++) {
            cout << a[i];
            if (i == num-1) {
                cout << endl;
            }
            else {
                cout << " ";
            }
        }
    }


    return 0;
}