#include <cstdio>
#include <queue>
using namespace std;

char dungeon[32][32][32];
int Distance[32][32][32];
int L, R, C;
const int direction[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
struct point_type{
    int x;
    int y;
    int z;
};
int BFS(int i, int j, int k)
{
    Distance[i][j][k] = 0;
    queue<point_type> q;
    q.push(point_type{i,j,k});
    dungeon[i][j][k] = '#';

    point_type cur, nxt;
    while (!q.empty()){
        cur = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i){
            nxt.x = cur.x + direction[i][0];
            nxt.y = cur.y + direction[i][1];
            nxt.z = cur.z + direction[i][2];

            if (nxt.x<0 || nxt.x >= L || nxt.y<0 || nxt.y >= R || nxt.z<0 || nxt.z>=C) continue;

            if (dungeon[nxt.x][nxt.y][nxt.z] != '#'){
                Distance[nxt.x][nxt.y][nxt.z] = Distance[cur.x][cur.y][cur.z] + 1;
                if (dungeon[nxt.x][nxt.y][nxt.z] == 'E')
                    return Distance[nxt.x][nxt.y][nxt.z];
                dungeon[nxt.x][nxt.y][nxt.z] = '#';
                q.push(nxt);
            }
        }
    }
    return -1;
}
int main()
{
   // freopen ("input.txt","rt",stdin);
    while (scanf("%d%d%d", &L, &R, &C)){
        if (!L && !R && !C) break;
        int start_i, start_j, start_k;

        for (int i = 0; i < L; ++i){
            for (int j = 0; j < R; ++j){
                scanf("%s",dungeon[i][j]);
                for (int k = 0; k < C; ++k)
                    if (dungeon[i][j][k] == 'S'){
                        start_i = i;
                        start_j = j;
                        start_k = k;
                    }
            }
        }
        int minute = BFS(start_i, start_j, start_k);

        if (minute != -1) printf("Escaped in %d minute(s).\n", minute);
        else printf("Trapped!\n");
    }
    return 0;
}