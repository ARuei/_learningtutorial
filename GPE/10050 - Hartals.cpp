#include <iostream>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    while(cases--) {

        int N, P;
        cin >> N >> P;
        //int days[3651] = {};
        int * days = new int [N+1]{};
        int * hartals = new int [P]{}; 
        for (int i=0; i<P; i++) {

            cin >> hartals[i];
            for (int j=hartals[i]; j<=N; j+=hartals[i]) {

                days[j] = 1;
            }
        }

        int cnt = 0;
        for (int i=0; i<=N; i++) {

            if (i%7==0 || i%7==6) continue;
            if (days[i]==1) ++cnt; 
        }

        cout << cnt << endl;

        delete [] days;
        delete [] hartals;
    }
}