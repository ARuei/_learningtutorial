#include <iostream>
#include <vector>
using namespace std;

int main() {

    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector <string> label = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int cases;
    int month, day, start, ret;
    cin >> cases;
    while(cases--) {

        start = 5; // 2011.12.31 Fri.
        cin >> month >> day;
        for(int i=0; i<month-1; i++) {
            start += months[i];
        }
        
        ret = (start+day)%7;
        cout << label[ret] << endl;
    }

    return 0;
}
