#include <iostream>

#define LIMIT 1000000

using namespace std;

int reverse_number(int n) {

    int remainder, reverse=0;
    while(n!=0) {

        remainder = n%10;
        reverse = reverse*10 + remainder;
        n /= 10;
    }

    return reverse;
}

int main() {

    // create a prime table
    // true := not prime 
    bool primeTable[LIMIT+5] = {true, true};
    for(int i=2; i<=LIMIT; i++) {

        if (!primeTable[i]) {
            for (int j=i+i; j<LIMIT; j+=i) {
            // label the multiple of prime number 

                primeTable[j] = true;
            }
        }
    }

    int num;
    while(cin >> num) {

        int retNum = reverse_number(num);
        //cout << retNum << endl;

        if (!primeTable[num]) {
            if(!primeTable[retNum] && retNum!=num) {

                cout << num << " is emirp." << endl;
            }
            else {
                
                cout << num << " is prime." << endl;
            }
        }
        else {

            cout << num << " is not prime." << endl;
        }
    }

    return 0;
}