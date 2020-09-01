#include <iostream>

using namespace std;

int main () {

    /* cdefgab */
    int tableFir[7][10] = {
        0,1,1,0,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,0,
        0,1,1,1,0,0,1,1,1,1, 
        0,1,1,1,0,0,1,1,1,0,
        0,1,1,1,0,0,1,1,0,0,
        0,1,1,1,0,0,1,0,0,0,
        0,1,1,1,0,0,0,0,0,0,
    };
    /* CDEFGAB */
    int tableSec[7][10] = {
        1,1,1,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,0,0,0,0,
        1,1,1,1,0,0,1,1,1,0,
        1,1,1,1,0,0,1,1,0,0,
        1,1,1,1,0,0,1,0,0,0,
        1,1,1,1,0,0,0,0,0,0,
    };

    int cases;

    cin >> cases;
    getchar();

    string str; 
    int *cur, *last;
    while(cases--) {

        int press[10] = {0};

        getline(cin, str);
        for (int i=0; i< str.size(); i++) {

            if( 'a'<=str[i] && str[i]<='g') {

                cur = tableFir[str[i]-'a'];
            }
            else {

                cur = tableSec[str[i]-'A'];
            }

            for (int j=0; j<10; j++) { // count-up the times of each finger
                if (cur[j]==1 && (i==0 ||last[j]==0)) {

                    ++press[j];
                }
            }

            last = cur;
        }

        for (int i=0; i<9; i++) {

            cout << press[i] << " ";
        }
        cout << press[9] << endl;
    }

    return 0;
}