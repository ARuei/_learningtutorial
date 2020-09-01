#include <iostream>
#include <memory.h>

using namespace std;

bool isRecorded [100000000] = {false};

int main () {

    int num;

    while(cin >> num) {

        if (!num) break;

        int count = 0, square;
        memset(isRecorded, false, sizeof(isRecorded));
        while (!isRecorded[num]) {

            ++count;
            isRecorded[num] = true;
            square = num * num;
            square /= 100;
            square %= 10000;
            num = square;
        }

        cout << count << endl;
    }

    return 0;
}