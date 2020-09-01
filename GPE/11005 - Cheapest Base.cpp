#include <iostream>

using namespace std;

int main() {

    int cases, cnt=0;
    cin >> cases;
    while(cases--) {

        int cost[36];
        for (int i=0; i<36; i++) {

            cin >> cost[i];
        }

        cout << "Case " <<  ++cnt << ":\n";

        int tests;
        cin >> tests;

        while(tests--) {

            int num;
            cin >> num;

            int min = 0;
            int base[37] = {};

            for (int i=2; i<37; i++) {

                int sum = 0;
                int temp = num;
                while(temp) {
                    int re = temp%i;
                    sum += cost[re];
                    temp /= i;
                }

                if(min==0 || sum<=min) {
                    base[i] = sum;
                    min = sum;
                }
            }

            cout << "Cheapest base(s) for number " << num << ":";
            for (int i=2; i<=36; i++) {

                if (base[i]==min) {

                    cout << " " << i;
                }
            }
            cout << endl;
        }

        if (cases>0) {
            cout << endl;
        }
    }

    return 0;
}