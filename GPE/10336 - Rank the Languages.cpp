#include <iostream>
#include <memory.h>

using namespace std;

char map[1000][1000] = {0};
bool isVisisted[1000][1000] = {0};

void DFS(int x, int y) {

    isVisisted[x][y] = 1;

    if (map[x+1][y] == map[x][y] && !isVisisted[x+1][y]) DFS(x+1, y);
    if (map[x-1][y] == map[x][y] && !isVisisted[x-1][y]) DFS(x-1, y);
    if (map[x][y+1] == map[x][y] && !isVisisted[x][y+1]) DFS(x, y+1);
    if (map[x][y-1] == map[x][y] && !isVisisted[x][y-1]) DFS(x, y-1);
}

int main () {

    int cases;
    cin >> cases;

    int H, W, maxarea, cnt = 0;
    while (cases--) {

        cin >> H >> W;

        memset(isVisisted, 0, sizeof(isVisisted));
        maxarea = 0;
        int letters[30] = {0}; // to record the max area of the letters

        for (int i=1; i<=H; i++) {
            cin >> map[i]+1;
        }
        /*
        for (int i=1; i<=H; i++) {
            for (int j=1; j<=W; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }
        */

        for (int i=1; i<=H; i++) {
            for (int j=1; j<=W; j++) {
                if(!isVisisted[i][j]) {

                    // each block will be considered as one area
                    maxarea = max( ++letters[map[i][j]-'a'], maxarea);
                    DFS(i, j); // marked all neighboring
                }
            }
        }

        cout << "World #" << ++cnt << endl; 

        for (int i=maxarea; i>=1; i--) {
            for (int j=0; j<26; j++) {
                if (letters[j] == i) {
                    cout << (char)('a'+j) << ": " << i << endl;
                }
            }
        }
        
    }

    return 0;
}