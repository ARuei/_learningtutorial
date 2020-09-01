#include <iostream>
#include <cstdio>

#define MODULE 131071

using namespace std;

int main () {

    string str, s_cat;
    while(true) {

        getline(cin, str);
        if (str == "") break;
        while (str[str.size()-1] !='#') {

            getline(cin, s_cat);
            str += s_cat;
        } 

        int num = 0;
        for (int i=0; i<str.size()-1; i++) {

            num<<=1;
            if (str[i]=='0' || str[i]=='1')
                num += str[i] - '0';

            /* 
             *  If it is divisible, the input number should be MODULE's multiplier.
             * 
             *  Because of the input digit condition, we need to recursively
             *  check the modularity in binary way.
             */
            while (num>=MODULE) num -= MODULE;
        }

        if (num%MODULE==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}