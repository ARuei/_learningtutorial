#include <iostream> 
#include <cstdlib> 

using namespace std;

int main(int argc, char ** argv) {

    long long int self, opponent;

    while(cin >> self >> opponent) {

        cout << abs(opponent - self) << endl;
    }

    return 0;
}