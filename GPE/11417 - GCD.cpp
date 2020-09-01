#include <iostream>

using namespace std;

int gcd(int x, int y) {

    if (y==0) return x;
    return gcd(y, x%y);
}

int GCD(int i, int j){
  while( ( i %= j ) && ( j %= i ) );
  return i + j;
}

int main() {

    int num;

    while (cin >> num && num != 0) {

        int sum = 0;

        for (int i=1; i<num; i++) {

            for (int j=i+1; j<=num; j++) {

                sum += gcd(i,j);
            }
        }

        cout << sum << endl;
    }

    return 0;
}