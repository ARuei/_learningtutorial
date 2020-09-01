#include <iostream>
#include <sstream>
#include <memory.h>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Team {

    bool isJoined;
    int id;
    int solved;
    int penalty;
    int error[10];
};

struct Team team[105];

bool cmp (Team t1, Team t2) {

    if (t1.solved != t2.solved) return t1.solved > t2.solved;
    else if (t1.penalty != t2.penalty) return t1.penalty < t2.penalty;
    else if (t1.id != t2.id) return t1.id < t2.id;
    return t1.id > t2.id;
}
 
int main () {

    int cases;
    string str;

    cin >> cases;
    getchar();
    getchar();

    for (int i=0; i<cases; i++) {

        if (i) cout << endl;
        for (int j=0; j<105; j++) {

            team[j].isJoined = false;
            team[j].id = j;
            team[j].solved = 0;
            team[j].penalty = 0;
            memset(team[j].error, 0, sizeof(team[j].error));
        }

        int contestant, problem, time;
        char label;
        while (getline(cin, str) && str != "") {

            stringstream ss;
            ss.str(str);
            ss >> contestant >> problem >> time >> label;

            team[contestant].isJoined = true;
            
            if (team[contestant].error[problem] == -1) continue; // Solved.

            if (label == 'C') {

                team[contestant].penalty += time + team[contestant].error[problem]*20; // The penalty of that problem.
                team[contestant].solved++;
                team[contestant].error[problem] = -1; // Marked as solved;
            }
            else if (label == 'I') {

                team[contestant].error[problem]++;
            }
            else {

            }
        }
        
        sort(team, team+105, cmp);

        for (int j=0; j<105; j++) {

            if (team[j].isJoined) {

                cout << team[j].id << " " << team[j].solved << " " << team[j].penalty << endl;
            }
        }
    }

    return 0;
}