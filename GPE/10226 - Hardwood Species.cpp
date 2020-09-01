#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {

    int cases;
    while(cin >> cases) {

        getchar(); /* '\n' */

        string ignore;
        getline(cin, ignore); /* blank  */
        
        while (cases--) {

            string str;
            map<string, int> tree;
            while (getline(cin, str) && str !="") {

                tree[str]++;
            }

            double sum = 0;
            map<string, int>::iterator iter;
            for (iter = tree.begin(); iter != tree.end(); ++iter) {

                sum += iter->second;
            }

            for (iter = tree.begin(); iter != tree.end(); ++iter) {

                cout << fixed << setprecision(4) << iter->first << " " << iter->second / sum * 100.0 << endl;
            } 
            
            if (cases>0) {
                cout << endl;
            }    
        }

    }

    return 0;
}