#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    
    int cases;
    cin >> cases;

    int players, target;
    double prob;
    while(cases--) {

        cin >> players >> prob >> target;

        if (prob==0.0) {
            cout << "0.0000" << endl;
        }

        else {
            double ret = prob * pow((1-prob), target-1) / (1-pow((1-prob), players));
            cout << fixed << setprecision(4) << ret << endl;
        }
    }

    return 0;
}
