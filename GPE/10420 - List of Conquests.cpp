#include <iostream>
#include <map>

using namespace std;

int main () {

    int line;
    cin >> line;

    char str[76] = {0};
    string country_name;
    map<string, int> group; // <name of country, counts>
    while (line!=0) {

        cin >> country_name;
        group[country_name]++;
        cin.getline(str, 76); 
        // others not important
        // not using cin >> str cuz the space will be escape condition
        // or just string stream with std::string s = getline(str)
        --line;
    }

    map<string, int>::iterator iter;
    for(iter=group.begin(); iter!=group.end(); ++iter) {
        cout << iter->first << " ";
        cout << iter->second << endl;
    }

    return 0;
}