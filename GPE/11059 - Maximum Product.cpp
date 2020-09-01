#include <iostream>

using namespace std;

int main() {

    int leng, cnt = 0;

    while (cin >> leng) {
        
        if (cin.eof()) break;
        
        int * elements = new int [leng];
        for (int i=0; i<leng; i++) {

            cin >> elements[i];
        }

        long long max = 0;
        for (int i=0; i<leng; i++) {
            
            long long temp = 1;
            for (int j=i; j<leng; j++) {

                temp *= elements[j];
                
                if (temp > max) {
                    max = temp;
                }
            }
        }

        cout << "Case #" << ++cnt << ": The maximum product is " << max << "." << endl << endl; 

        delete [] elements;
    }

    return 0;
}