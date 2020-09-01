#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

using namespace std;

int main () {

    int testcases;
    cin >> testcases;
    
    getchar();
    string ignore;
    getline(cin, ignore);

    while(testcases--) {

        int num;
        cin >> num;

        vector<int> connected_pair(num+1); // to match the index

        for (int i=1; i<=num; i++) {
        // originally, initialize with its own index
            connected_pair[i] = i;
        }

        getchar();

        char type;
        int src, dst, wrong_res = 0, right_res = 0;
        string str;
        while(getline(cin, str)) {

            if (str=="") break;

            stringstream ss(str);
            ss >> type >> src >> dst;

            if (type=='c') {

                // derive the tags of src and dst in a link pair
                int src_tag = connected_pair[src];
                int dst_tag = connected_pair[dst];

                for (int i=1; i<=num; i++) {

                    // point to the origin forcely (the minmum of the index)
                    if(connected_pair[i]==src_tag || connected_pair[i]==dst_tag) {

                        connected_pair[i] = min(src_tag, dst_tag);
                    }
                }
            }
            else if (type=='q') {

                if ( connected_pair[src] != connected_pair[dst]) {

                    ++wrong_res;
                }
                else {

                    ++right_res;
                }
            }
        }

        cout << right_res << "," << wrong_res;
        if (testcases==0) {
            cout << endl;
        }
        else {
            cout << endl << endl;
        }
    }

    return 0;
}