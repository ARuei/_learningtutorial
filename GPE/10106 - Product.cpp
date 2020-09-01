#include <iostream>
#include <vector>

#define MAX(x,y) (((x)>(y)) ? (x):(y))

using namespace std;

void reverseStr(vector<int> &vec, const string str) {

    for (int i=str.size()-1; i>=0; i--) {

        vec[vec.size()-i-1] = str[i]-'0';
    }
    
    /*
    vector<int>::iterator iter;
    for (iter=vec.begin(); iter!=vec.end(); iter++) {

        cout << *iter;
    }
    cout << endl;
    */
}

int main() {

    string num_1, num_2;
    while (getline(cin, num_1) && getline(cin, num_2)) {

        if (cin.eof()) break;

        if (num_1=="0" || num_2=="0") {
            cout << 0 << endl;
            continue;
        }

        vector<int> vec_1(num_1.size()), vec_2(num_2.size());

        reverseStr(vec_1, num_1);
        reverseStr(vec_2, num_2);

        int idx = MAX(vec_1.size(), vec_2.size());

        vector<int> res(idx*idx, 0);
        for (int i=0; i<vec_1.size(); i++) {
            for (int j=0; j<vec_2.size(); j++) {

                res[i+j] += vec_1[i] * vec_2[j];
                if (res[i+j]>9) {
                    res[i+j+1] += res[i+j]/10;
                    res[i+j] %= 10;
                }
            }
        }

        vector<int>::reverse_iterator rit;
        for (rit=res.rbegin(); rit!=res.rend(); ++rit) {

            if (*rit==0) {

                if (!(*(rit+1))) {
                    res.pop_back();
                    continue;
                }
                else {
                    res.pop_back();
                    break;
                }

            }
        }

        for (rit=res.rbegin(); rit!=res.rend(); ++rit) {

            cout << *rit;
        }
        cout << endl;
    }

    return 0;
}