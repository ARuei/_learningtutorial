#include <iostream>
#include <cstdio>

#define Margin 100

using namespace std;

void visit(char map[][Margin+5], bool isVisited[][Margin+5], int i, int j) {

    if (map[i][j]=='@' && !isVisited[i][j]) {

        isVisited[i][j] = true;
        visit(map, isVisited, i, j+1);
        visit(map, isVisited, i, j-1);
        visit(map, isVisited, i+1, j);
        visit(map, isVisited, i-1, j);
        visit(map, isVisited, i+1, j-1);
        visit(map, isVisited, i-1, j-1);
        visit(map, isVisited, i+1, j+1);
        visit(map, isVisited, i-1, j+1);
    }
}

int main () {

    int m, n;
    while(cin >> m >> n) {

        if (!m || !n) break;

        getchar();

        char map[Margin+5][Margin+5] = {0};
        bool isVisited[Margin+5][Margin+5] = {0};

        for (int i=1; i<=m; i++) {
            cin >> map[i]+1;
        }

        int count = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {

                if (map[i][j]=='@' && !isVisited[i][j]) {

                    count++;
                    visit(map, isVisited, i, j);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}