#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() {

    int num;
    while (cin >> num) {

        bool jolly_jud = true;
        int count=1;
        int * seq = new int [num];
        for (int i=0; i<num; i++) {

            cin >> seq[i];
        }

        set <int> jolly;
        for (int i=0; i<num-1; i++) {
            
            int d = abs(seq[i] - seq[i+1]);
            if (1 <= d && d < num) {
                jolly.insert(d);
            }
            else {
                jolly_jud = false;
                break;
            }
        }

        if (jolly.size() == num-1 && jolly_jud) {

            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
        
        delete [] seq;
    }

    return 0;
}
