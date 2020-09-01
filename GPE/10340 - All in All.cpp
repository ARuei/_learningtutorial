#include <iostream>

using namespace std;

int main() {

    string s, t;

    while (cin >> s >> t) {

        int sindex = 0;
        for (int i=0; i<t.size(); i++) {

            if (s[sindex] == t[i]) {

                sindex++;
                if (sindex == s.size()) break;
            }
        }

        if (sindex==s.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}