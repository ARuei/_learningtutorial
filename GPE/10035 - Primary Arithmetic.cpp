#include <iostream>
#include <memory.h>
#include <vector>

#define max(x, y) ((x)>(y)?(x):(y))

using namespace std;

struct aNum
{
    int cnt;
    int digits[11];
}; // if *digits run-time error

aNum getDigits(int number) {

    int i=0, digits[11] = {0}; // Each digit should be initialzed as 0
    while (number > 0) {

        digits[i] = number%10;
        number = number/10;
        i++;
    }
    
    aNum retval;
    retval.cnt = i;
    memcpy(retval.digits, digits, sizeof(digits));

    return retval;
}

pair<int, vector<int>> getDigits_alter(int number) {

    int i=0;
    vector<int> digits; 
    while (number > 0) {

        digits.push_back(number%10);
        number = number/10;
        i++;
    }

    return make_pair(i, digits);
}

void displayDigits(aNum number) {

    cout << "Display each digits" << endl;
    for (int i=0; i<number.cnt; i++) {

        cout << number.digits[i] << " ";
    }
    cout << endl;
}

void displayDigits_alter(pair<int, vector<int>> &p) {

    cout << "Display each digits - vector" << endl;
    vector<int>::iterator it;
    for(it=p.second.begin(); it!=p.second.end(); ++it) {

        cout << *it << " ";
    }      
    cout << endl;
}

int main(int argc, char *argv[]) {

    int in_num1, in_num2, max_digit;
    while (cin >> in_num1 >> in_num2) {

        if (in_num1 == 0 && in_num2 == 0) break;
        aNum num1 = getDigits(in_num1);
        aNum num2 = getDigits(in_num2);
        max_digit = max(num1.cnt, num2.cnt);

        /*

        pair<int, vector<int>> p1 = getDigits_alter(in_num1);
        pair<int, vector<int>> p2 = getDigits_alter(in_num2);              

        displayDigits_alter(p1);
        displayDigits_alter(p2);
        displayDigits(num1);
        displayDigits(num2);

        cout << "max_digit := " << max_digit << " = " <<num1.cnt << " - " << num2.cnt << endl;

        */

        int carrier = 0;
        int sum[12] = {0};
        for (int i=0; i<max_digit; i++) {

            sum[i] += (num1.digits[i] + num2.digits[i]);
            if (sum[i] >= 10) {
                sum[i+1]++;
                carrier++;
            }
        }

        switch (carrier) { 
            case 0:
                cout << "No carry operation." << endl;
                break;
            case 1:
                cout << "1 carry operation." << endl;
                break;
            default:
                cout << carrier << " carry operations." << endl;
                break;
        }
    }

    return 0;
}