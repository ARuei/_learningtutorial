#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

bool cmp (int x, int y) {

    return x > y;
}

int main () {

    int numOfStudents;
    while (cin >> numOfStudents) {

        if (!numOfStudents) break;

        getchar();

        int first, second, avg = 0, cnt, ans = 0;
        int cost[1005] = {0};
        for (int i=0; i<numOfStudents; i++) {

            scanf("%d.%d", &first, &second);
            cost[i] = first*100+second;
            avg += cost[i];
        }

        cnt = avg%numOfStudents;
        avg /= numOfStudents; 

        sort(cost, cost+numOfStudents, cmp);

        for (int i=0; i<cnt; i++) {

            ans += abs(cost[i] - (avg+1));
        }
        for (int i=cnt; i<numOfStudents; i++) {

            ans += abs(cost[i] - avg);
        }

        cout << fixed << setprecision(2) << "$" << ans/200.0 << endl;
    }

    return 0;
}