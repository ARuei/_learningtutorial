#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second==p2.second) {
        return p1.first > p2.first;
    }
    return p1.second<p2.second;
}

int main() {

    string str;
    bool isFirst = true;
    while (getline(cin, str)) {

        if (!isFirst && str.size()!=0) {

            cout << endl;
        }

        map<int, int> ascii;
        vector<pair<int, int>> vec;

        for (int i=0; i<str.size(); i++) {

            ascii[char(str[i])]++;
        }

        map<int, int>::iterator iter;
        for (iter=ascii.begin(); iter!=ascii.end(); iter++) {

            vec.push_back(make_pair(iter->first, iter->second));
        }

        sort(vec.begin(), vec.end(), cmp);

        vector<pair<int, int>>::iterator it;
        for (it=vec.begin(); it!=vec.end(); it++) {

            cout << it->first << " " << it->second << endl;
        }

        isFirst = false;
    }


    return 0;
}