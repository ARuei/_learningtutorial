#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Apperance {

    int times;
    char c;
};

bool cmp (Apperance x, Apperance y) {

    if (x.times == y.times) return x.c < y.c;
    else return x.times > y.times;
}

int main () {

    int line;
    cin >> line;
    cin.ignore(); // escape the <enter> 

    Apperance a[26];
    for (int i=0; i<26; i++) {
        a[i].times = 0;
        a[i].c = i+65; // 'A is started from 65, by (int)'A'
    } // initialization

    //cin.ignore(); // escape the <enter> 
    //scanf("%d\n",&line);

    char str[10000];
    while (line--) {

        cin.getline(str, 10000);
        for (int i=0; i<strlen(str); i++) {

            if (isalpha(str[i])) {
                if (islower(str[i])) { 
                    str[i] -= 32; // could be derive by 'a' - 'A'
                }
                a[(int)str[i]-65].times++;
            }
        }
    }

    sort(a, a+26, cmp);
    for (int i=0; i<26, a[i].times>0; i++) {

        cout << a[i].c << " " << a[i].times << endl;
    }

    return 0;
}