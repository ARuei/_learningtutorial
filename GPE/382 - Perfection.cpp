#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main () {

    int num;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> num) {

        if (!num) break;
        
        int s = (int)sqrt(num+0.0);
        
        int sum = 1;
        for (int i=2; i<=s; i++) {
            if (num%i==0) {

                sum += i + num/i;
            }
        }

        if (s*s==num) {
            sum -= s;
        }

        printf("%5d  ", num);
        if (sum == num) {
            cout << "PERFECT" << endl;
        }
        else if (sum < num) {
            cout << "DEFICIENT" << endl;
        }
        else if (sum > num) {
            cout << "ABUNDANT" << endl;
        }
        
    }
    cout << "END OF OUTPUT" << endl;


    return 0;
}