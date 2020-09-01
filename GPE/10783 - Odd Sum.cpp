#include <iostream>

using namespace std;

bool isOdd(int x) {

    if (x%2!=0) {
        return true;
    }
    else return false;
}

int main() {

    int cases;

    int a, b, cnt=1;
    cin >> cases;
    while (cases--) {

        cin >> a >> b;

        int sum = 0;
        for (int i=a; i<=b; i++) {

            if (isOdd(i)) {
                //cout << i << endl;
                sum+=i;
            }
        }

        cout << "Case " << cnt++ << ": "<< sum << endl;   
    }

    return 0;
}