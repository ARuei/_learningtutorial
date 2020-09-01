#include <iostream>

using namespace std;

int main() {

    string str;
    while(getline(cin, str)) {

        int sum = 0;
        int base = 1;
        for (int i=0; i<str.size(); i++) {

            int convertedValue = 0;

            if(isdigit(str[i])) {

                convertedValue = str[i] - '0';
            }
            else if (isupper(str[i])) {

                convertedValue = str[i] - ('A' - 10);
            }
            else if (islower(str[i])) {

                convertedValue = str[i] - ('a' - 26 - 10);
            }

            sum += convertedValue;

            /*
             *  To derive the largest index, that is, 
             *  at least within this base system.
             */
            if (convertedValue > base) { 
                base = convertedValue;
            }
        }

        for (int i=base; i<=62; i++) {

            /*
             *  If the summation of each digits in x-based system
             *  can be devided by i, and then it should be (i+1) base.
             */ 
            if (sum%i==0) {

                cout << i+1 << endl;
                break;
            }
            else if (i==62) {

                cout << "such number is impossible!\n";
            }
        }
    }

    return 0;
}