#include <iostream>
#include <cstdio>

using namespace std;

void convert2digits(string &str) {

    for (int i=0; i<str.size(); i++) {

        if(!isdigit(str[i])) {

            str.erase(i, 1);
            --i; // adjust the index
        }
    }
}

int main() {

    int num, cnt=0;
    while (cin >> num) {

        if (num == 0) break;

        string solution = "";
        string submission = "";
        string str;

        getchar(); // '\n' 

        bool ac = true;
        for (int i=0; i<num; i++) {

            getline(cin, str);

            if (!i) {
                solution = str;
            }
            else {
                solution += ('\n' + str);
            }
        }

        cin >> num;
        getchar();

        for (int i=0; i<num; i++) {

            getline(cin, str);

            if (!i) {
                submission = str;
            }
            else {
                submission += ('\n' + str);
            }
        }

        solution == submission ? (ac=true) : (ac=false);

        if (ac) {

            cout << "Run #" << ++cnt << ": Accepted" << endl;
            continue;
        }

        bool pe = true;

        convert2digits(solution);
        convert2digits(submission);

        solution == submission ? (pe=true) : (pe=false);

        if (pe) {

            cout << "Run #" << ++cnt << ": Presentation Error" << endl;
            continue;
        }     
        else {

            cout << "Run #" << ++cnt << ": Wrong Answer" << endl;
        }   

    }

    return 0;
}