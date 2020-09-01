#include <iostream>
#include <vector>

using namespace std;

vector <int> derive_binary_representation(int n, int &counter) {

    vector <int> vec;

    while (n) {
        if(n%2) {
            counter++;
        }
        vec.push_back(n%2);
        n/=2;
    }

    return vec;
}

int main() {

    int I;
    while(cin >> I) {
        if(I == 0) break;

        int cnt = 0;
        vector <int> ret = derive_binary_representation(I, cnt);
        
        cout << "The parity of ";
        for(int i=ret.size()-1; i>=0;i--) {

            cout << ret[i];
        }
        cout << " is " << cnt << " (mod 2)." << endl;

    }

    return 0;
}