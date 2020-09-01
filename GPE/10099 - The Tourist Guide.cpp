#include <iostream>
#include <sstream>
#include <memory.h>

#define N 100

using namespace std;

int main () {

    int cities, road_segments, cnt = 0;
    int capacities[N+5][N+5] = {0};
    while (cin >> cities >> road_segments) {

        if (!cities || !road_segments) break;

        cin.ignore();
        memset(capacities, 0, sizeof(capacities));

        stringstream ss;
        string str;
        int C1, C2, P;
        for (int i=0; i<road_segments; i++) {

            ss.str(""), ss.clear();
            getline(cin, str);
            ss.str(str);
            ss >> C1 >> C2 >> P;
        
            capacities[C1][C2] = P;
            capacities[C2][C1] = capacities[C1][C2];
        }

        for (int k=1; k<=cities; k++) {
            for (int i=1; i<=cities; i++) {
                for (int j=1; j<=cities; j++) {
                    capacities[i][j] = max(capacities[i][j], min(capacities[i][k], capacities[k][j]));
                }
            }
        }

        int S, D, T;
        cin >> S >> D >> T;

        cout << "Scenario #" << ++cnt << endl;
        cout << "Minimum Number of Trips = " << T/(capacities[S][D]-1) + (T%(capacities[S][D]-1)!=0) << endl;
        cout << endl;
    }

    return 0;
}