#include <iostream>
#include <algorithm> 
#include <memory.h>

#define N 100000

using namespace std;

int main () {

    string str;
    while (getline(cin, str)) {

        if (str=="") break;

        string ori, rev;
        ori = str;
        reverse(str.begin(), str.end());
        rev = str;

        int failure[N+5] = {0};

        for (int i=1, j=failure[0]=-1; i<rev.size(); i++) {

            while (j>=0 && rev[j+1]!=rev[i]) j = failure[j];
            if (rev[j+1]==rev[i]) j++;
            failure[i] = j;
        }

        /*
        for (int i=0; i<rev.size(); i++) {

            cout << failure[i] << " ";
        }
        cout << endl;
        */

        int cnt;
        for (int i=0, j=-1; i<rev.size(); i++) {
        /* Find out the subsequence of reverse string in origin string 
         * and make it become palindrome.
         * */
            while (j>=0 && rev[j+1]!=ori[i]) j = failure[j];
            if (rev[j+1]==ori[i]) j++;
            cnt = j;
        }
        // cout << cnt << " " << rev.size() << endl;
        ++cnt; // Just consider it as the duplicated index

        for (int i=0; i<ori.size(); i++) {
            cout << ori[i];
        }
        for (; cnt<rev.size(); cnt++) {
            cout << rev[cnt];
        }
        cout << endl;
    }

    return 0;
}