#include <iostream>

#define LIMIT 100000

using namespace std;

struct POINT {

    int x, y;
};

struct POINT pt[LIMIT+1];

void create() {

    pt[1].x = 0;
    pt[1].y = 0;
    int cnt, index = 2;

    int now_x = pt[1].x, now_y = pt[1].y;
    for (int layer = 1; index<=LIMIT; layer++) {

        for (cnt=0; cnt<layer && index<=LIMIT; index++, cnt++) {

            pt[index].x = now_x;
            pt[index].y = ++now_y;
        }
        for (cnt=0; cnt<layer-1 && index<=LIMIT; index++, cnt++) {

            pt[index].x = --now_x;
            pt[index].y = ++now_y;   
        }
        for (cnt=0; cnt<layer && index<=LIMIT; index++, cnt++) {

            pt[index].x = --now_x;
            pt[index].y = now_y;              
        }
        for (cnt=0; cnt<layer && index<=LIMIT; index++, cnt++) {

            pt[index].x = now_x;
            pt[index].y = --now_y;              
        }
        for (cnt=0; cnt<layer && index<=LIMIT; index++, cnt++) {

            pt[index].x = ++now_x;
            pt[index].y = --now_y;              
        }
        for (cnt=0; cnt<layer && index<=LIMIT; index++, cnt++) {

            pt[index].x = ++now_x;
            pt[index].y = now_y;              
        }
    }

}

int main(){

    create();
    int num;
    while (cin >> num) {

        if (cin.eof()) break;

        cout << pt[num].x << " " << pt[num].y << endl;
    }

    return 0;
}