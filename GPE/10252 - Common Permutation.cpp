#include <iostream>

using namespace std;

int main () {

    string str1, str2;

    while(getline(cin, str1)) {

        getline(cin, str2);

        int str1Count[26] = {0};
        int str2Count[26] = {0};

        for (int i=0; i<str1.length(); i++) {

            ++str1Count[(int)(str1[i]-'a')];
        }
        for (int i=0; i<str2.length(); i++) {

            ++str2Count[(int)(str2[i]-'a')];
        }

        for (int i=0; i<26; i++) {
            int less = min(str1Count[i], str2Count[i]);

            for (int j=0; j<less; j++) {

                cout << (char)(i+'a');
            }
        }

        cout << endl;
    } 

    return 0;
}


/*
#include <iostream>

#define MIN(x,y) ((x)<(y)?(x):(y))

using namespace std;

void getCounted(const string &s, int counter []) {

    for (int i=0; i<s.length(); i++) {

        ++counter[(int)(s[i]-'a')]; // derive the offset started from \a
        
        
        for (int j=0; j<30; j++) {
            cout << counter[j] << " ";
        }
        cout << endl << endl;
        
    }
}

int main () {

    string a, b;
    while( getline(cin, a) ) {

        getline(cin, b);

        int count_a[26] = {0}, count_b[26] = {0};

        getCounted(a, count_a);
        getCounted(b, count_b);

        for (int i=0; i<26; i++) {

            int less_count = MIN(count_a[i], count_b[i]);
            for (int j=0 ; j<less_count; j++) { 
            // output the consecutive character of the less counted array 
                cout << (char)(i + 'a');
            }
        }

        cout << endl;
    }

    return 0;
}
*/