#include <iostream>

using namespace std;

int converstion(string str) {

    int num = 0;
    for (int i=0; i<str.size(); i++) {

        num <<= 1;
        //cout << num << " ";
        num += str[i] - '0';
        //cout << num << endl;
    }
    
    return num;
}

int gcd(int x, int y){

    if(y==0) return x;
    return gcd(y, x%y);
}

int main() {

    int cases;

    cin >> cases;

    int cnt = 0;
    while (cases--) {

        string s1, s2;
        cin >> s1 >> s2;

        int a = converstion(s1);       
        int b = converstion(s2); 

        int ret = gcd(a, b); 

        cout << "Pair #" << ++cnt << ": ";
        if (ret != 1) { // if the maximum is not one, there must be other factors
            cout << "All you need is love!" << endl;
        }
        else {

            cout << "Love is not all you need!" << endl;
        }
    }

    return 0;
}