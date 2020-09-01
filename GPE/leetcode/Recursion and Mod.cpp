#include <iostream>

using namespace std;

int calc(int a, long long num, int b) {

    if (num==1) return 3;
    else {
        long long result = calc(a, num/2, b);

        if (num%2==1) {
            return (result*result*3)%b;
        }
        else {
            return (result*result)%b;
        }
    }
}


int main () {

    long long num;

    while (cin >> num) {

        num = calc(3, num, 1000000009);
        cout << num-2 << endl; // i-th ans := 3's i's power - 2
    }    

    return 0;
}