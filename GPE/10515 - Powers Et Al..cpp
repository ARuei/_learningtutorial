#include <iostream>

using namespace std;

int powerTable[10][4] = {

    0,0,0,0,
    1,1,1,1,
    6,2,4,8,
    1,3,9,7,
    6,4,6,4,
    5,5,5,5,
    6,6,6,6,
    1,7,9,3,
    6,8,4,2,
    1,9,1,9
}; // rearraged to meet with the modulation

int main () {

    string str1, str2;

    while (cin >> str1 >> str2) {

        if (str1[0] == '0' && str2[0] == '0') break;
        if (str2=="0") { 
            cout << 1 << endl;
            continue;
        }
        long long value = 0;
        for(int i=0; i<str2.size(); i++) { 
            value = value*10 + str2[i] - '0';
            value %= 4; // in case of the large power
        }

        // only derive the last digit
        cout << powerTable[str1[str1.size()-1]-'0'][value%4] << endl;
    }

    return 0;
}