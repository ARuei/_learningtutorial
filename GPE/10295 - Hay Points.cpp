#include <iostream>
#include <map> 

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    map<string, int> dict;
    
    string str;
    int salary;
    while (m--) {

        cin >> str;
        cin >> salary;
        dict[str] = salary;
    }

    while (n--) {

        int sum = 0;
        while (cin>>str) {

            if (str==".") break;
            sum += dict[str];
        }

        cout << sum << endl;
    }

    return 0;

}