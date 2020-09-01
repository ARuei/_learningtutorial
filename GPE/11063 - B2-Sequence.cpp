#include <iostream>

using namespace std;

int main() {

    int items, cnt=0;
    while (cin >> items) {

        bool isB2 = true;
        int * arr = new int [items];

        for(int i=0; i<items; i++) {
            cin >> arr[i];
        }        

        // check for increasing order 
        for(int i=0; i<items; i++) {
            if (arr[i]<=arr[i-1]) {

                isB2 = false;
            }
        }   

        bool checkList[20001] = {};
        if (isB2) {
            for (int i=0; i<items; i++) {
                for (int j=i; j<items; j++) {

                    if (checkList[arr[i]+arr[j]]) { // the summation of arr[i] and arr[j] has existed by previous run
                        isB2 = false;
                        break;
                    }
                    else {
                        checkList[arr[i]+arr[j]] = 1;
                    }
                }
            }
        }


        isB2 == true ? cout << "Case #" << ++cnt << ": It is a B2-Sequence.\n\n" : cout << "Case #" << ++cnt << ": It is not a B2-Sequence.\n\n";
    }

    return 0;
}