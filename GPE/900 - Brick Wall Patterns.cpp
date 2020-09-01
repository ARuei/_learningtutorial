#include <iostream>

using namespace std;

int main() {

    long long int fib[51] = {1,1};

    for (int i=2; i<51; i++) {

        fib[i] = fib[i-1] + fib[i-2]; 
    }

    int num;

    while (cin >> num) {

        if (num == 0) break;

        cout << fib[num] << endl;
    }

    return 0;
}