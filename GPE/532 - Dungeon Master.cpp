#include <iostream>
#include <queue>
using namespace std;

char maze[35][35][35];
int dist[35][35][35];
int L, R, C;
const int direction[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1} };

struct point_type {

    int x;
    int y;
    int z;
};

int BFS(int x, int y, int z) {

    queue<point_type> q;
    q.push(point_type{x, y, z});
    dist[x][y][z] = 0;
    maze[x][y][z] = '#';

    point_type cur, next;
    while (!q.empty()) {
        
        cur = q.front();
        q.pop();

        for (int i=0; i<6; i++) {

            next.x = cur.x + direction[i][0];
            next.y = cur.y + direction[i][1];
            next.z = cur.z + direction[i][2];

            if (next.x < 0 || next.x >= L || next.y < 0 || next.y >= R || next.z < 0 || next.z >= C) {
                continue;
            }

            if (maze[next.x][next.y][next.z] != '#') {

                dist[next.x][next.y][next.z] = dist[cur.x][cur.y][cur.z] + 1;

                if (maze[next.x][next.y][next.z] == 'E') {
                    return dist[next.x][next.y][next.z];
                }

                maze[next.x][next.y][next.z] = '#';

                q.push(next);
            }
        }
    }

    return -1;
}

int main () {

    while (cin >> L >> R >> C) {

        if (!L && !R && !C) break;

        int start_i, start_j, start_k;
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {

                cin >> maze[i][j];
                for (int k=0; k<C; k++) {

                    if (maze[i][j][k] == 'S') {

                        start_i = i;
                        start_j = j;
                        start_k = k;
                    }
                }
            }
        }

        /*
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                for (int k=0; k<C; k++) {
                    cout << maze[i][j][k];
                }
                cout << endl;
            }
        }
        */


        int ret = BFS(start_i, start_j, start_k);
        if (ret==-1) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << ret << " minute(s)." << endl;
        }
    }

    return 0;
}