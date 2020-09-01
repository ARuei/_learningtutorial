#include <iostream>
#include <stdio.h>
#include <memory.h>

#define N 10

using namespace std;

char maze [N+5][N+5];
char steps [N+5][N+5];
int mines [N+5][N+5];

int main () {

    int games;
    cin >> games;

    int size; 
    while (games--) {

        cin >> size;
        getchar();

        memset(maze, 0, sizeof(maze));
        memset(steps, 0, sizeof(steps));
        memset(mines, 0, sizeof(mines));

        for (int i=0; i<size; i++) {
            cin >> maze[i];
        }

        for (int i=0; i<size; i++) {
            cin >> steps[i];
        }

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {

                if (maze[i][j] == '*') {
                    for (int ii=i-1; ii<=i+1; ii++) {
                        for (int jj=j-1; jj<=j+1; jj++) {
                            if (ii<0 || ii>=size || jj<0 || jj>=size) {
                                continue;
                            }

                            mines[ii][jj]++;
                        }
                    }
                }
            }
        }

        bool isOver = false;
        for (int i=0; i<size && !isOver; i++) {
            for (int j=0; j<size; j++) {

                if (steps[i][j]=='x' && maze[i][j]=='*') {

                    isOver = true;
                    break;
                }
            }
        }    

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {

                if (isOver) {
                    if (maze[i][j] == '*') {
                        cout << "*";
                    }
                    else if (steps[i][j] == 'x') {
                        cout << mines[i][j];
                    }
                    else {
                        cout << ".";
                    }
                }
                else {
                    if (steps[i][j] == 'x') {
                        cout << mines[i][j];
                    }
                    else {
                        cout << ".";
                    }
                }

            }
            cout << endl;
        }

        if (games) {
            cout << endl;
        }

    }

    return 0;
}