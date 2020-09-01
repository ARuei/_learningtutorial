#include <iostream>

using namespace std;

int main() {

    int number;
    while (cin>>number) {
        if (number == 0) break;

        string str;
        int up=1, north=2, west=3, south=5, east=4, down=6;
        while (number--) {

            cin >> str;
            int temp;
            if (str == "north") {

                temp = up;
                up = south;
                south = down;
                down = north;
                north = temp;
            }
            else if (str == "south") {

                temp = up;
                up = north;
                north = down;
                down = south;
                south = temp;
            }
            else if (str == "west") {

                temp = up;
                up = east;
                east = down;
                down = west;
                west = temp;
            }
            else if (str == "east") {

                temp = up;
                up = west;
                west = down;
                down = east;
                east = temp;
            }                        
        }

        cout << up << endl;
    }

    return 0;
}