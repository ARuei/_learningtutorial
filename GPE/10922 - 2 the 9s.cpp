#include <iostream>
using namespace std;

int examine_nine(const string str) {

    int sum = 0;
    for (int i=0; i<str.size(); i++) {

        sum += str[i]-'0';
    }

    return sum;
}

int main() {

    string str;
    while (getline(cin, str)) {

        if (str.size()==1 && str[0]=='0') break; 

        int cnt = 0;
        int ret = examine_nine(str);
        while (ret%9==0 && ret!=9) {

            int sum = 0;
            for (;ret;ret/=10) {
                sum+=ret%10;
            }
            ret = sum;
            ++cnt;
        }
        if (ret==9) {
            ++cnt;
        }

        if (cnt>0) {
            cout << str << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
        }
        else {
            cout << str << " is not a multiple of 9.\n";
        }
    }

    return 0;
}