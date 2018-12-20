#include <iostream>

using namespace std;

int main() {

    long long int DP[51] = {1, 1};
    for (int i=2; i<=50; i++) {

        DP[i] = DP[i-1] + DP[i-2];
    }

    int n;
    while (cin >> n && n!=0) {

        cout << DP[n] << endl;
    }

    return 0;
}


/*
#include <iostream>
#include <cmath>

using namespace std;

long long int fib(int);

int main() {

    int len;
    long long int res;

    while(cin>>len && len!=0) {

        res = fib(len);

        cout << res << endl;
    }

    return 0;
}

long long int fib(int inx) {

    if (inx==1) return 1;
    if (inx==2) return 2;
    if (inx==3) return 3;

    //cout << inx << endl << endl;
    long long int fnum;
    for (int i=1; i<=(inx+1); i++) {

        fnum = (pow((1+sqrt(5))/2, i) - pow((1-sqrt(5))/2, i)) / sqrt(5);
    }

    return fnum;
}
*/
