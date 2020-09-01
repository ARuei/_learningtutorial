#include <iostream>
#include <sstream>

using namespace std;

int main () {

    int cases;
    cin >> cases;

    int instrutions;
    while (cases--) {

        cin >> instrutions;
        int * steps = new int [instrutions];

        cin.ignore();

        int origin = 0;
        string str; 
        for (int i=0; i<instrutions; i++) {

            getline(cin, str);
            if (str == "LEFT")  {
                steps[i] = -1;
                --origin;
            }
            else if (str == "RIGHT") {
                steps[i] = 1;
                ++origin;
            }
            else {
                stringstream ss;
                ss.str(str);
                int num;
                string same, as;
                ss >> same >> as >> num;

                steps[i] = steps[num-1];
                origin += steps[num-1];
            }
        }

        cout << origin << endl;
        delete [] steps;
    }

    return 0;
}