#include <iostream>
#include <cstring>

using namespace std;

int main () {

    char mapping[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    char c;
    while (cin.get(c)) {

        c = tolower(c);
        char * p = strchr(mapping, c);
        if (p) { // if found, output the char two keys backward

            cout << *(p-2);
        }
        else {

            cout << c;
        }
    }

    return 0;
}