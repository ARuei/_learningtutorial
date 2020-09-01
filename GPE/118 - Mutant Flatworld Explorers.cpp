#include <iostream>

using namespace std;

struct Point {

    int x;
    int y;

    void setAxis(int a, int b) {
        x = a;
        y = b;
    }
};

int main() {

    Point origin;
    origin.setAxis(0, 0);

    int in_x, in_y;
    cin >> in_x >> in_y;
    Point upperRight;
    upperRight.setAxis(in_x, in_y);

    pair<int, int> move[5];
    move[0].first = 0; move[0].second = 1;
    move[1].first = 1; move[1].second = 0; 
    move[2].first = 0; move[2].second = -1; 
    move[3].first = -1; move[3].second = 0;  

    char ori;
    bool lost, map[55][55] = {0};
    string intruction;
    char dirLabel[5] = {'N','E','S','W'}; 
    while (cin >> in_x >> in_y >> ori) {

        lost = false;

        Point loc;
        loc.setAxis(in_x, in_y);

        int direction;
        switch(ori) {
            case 'N': direction = 0; break;
            case 'E': direction = 1; break;
            case 'S': direction = 2; break;
            case 'W': direction = 3; break;
        }

        getchar();
        getline(cin, intruction);

        for (int i=0; i<intruction.size() && !lost ; i++) {

            if (intruction[i]=='L') {
                
                switch (direction) {
                    case 0: direction = 3; break;
                    case 1: direction = 0; break;
                    case 2: direction = 1; break;
                    case 3: direction = 2; break;    
                } 
            }
            else if (intruction[i]=='R') {
                
                switch (direction) {
                    case 0: direction = 1; break;
                    case 1: direction = 2; break;
                    case 2: direction = 3; break;
                    case 3: direction = 0; break;    
                } 
            }   
            else if (intruction[i]=='F') {

                loc.x += move[direction].first;
                loc.y += move[direction].second;

                if (loc.x < origin.x || loc.y < origin.y || loc.x > upperRight.x || loc.y > upperRight.y) {

                    loc.x -= move[direction].first;
                    loc.y -= move[direction].second;

                    if (!map[loc.x][loc.y]) {
                        lost = true;
                        map[loc.x][loc.y] = true;
                    }
                }
            }         
        }

        cout << loc.x << " " << loc.y << " "<< dirLabel[direction];
        if (lost) cout << " LOST";
        cout <<endl;
    }

    return 0;
}