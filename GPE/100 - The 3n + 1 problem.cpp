#include <iostream>

#define max(x,y) ((x)>(y)?(x):(y))

#define min(x,y) ((x)<(y)?(x):(y))

using namespace std;

int calc_cycle_len(int num) {

    int cycle_len = 1;
    while(num!=1) {

        if(num%2) {

            num = 3*num + 1; 
            
            // must be even skip for the next run
            num = num >> 1;
            cycle_len+=2; 
        }
        else {

            num = num >> 1;
            cycle_len++;
        }
    }

    return cycle_len;
}

int get_res(int lower, int upper) {

    int ret=0, temp;
    for (int i=lower; i<=upper; i++) { // iterate from lower to upper (each number)

        temp = calc_cycle_len(i);

        if (ret < temp) ret = temp;
    }

    return ret;
}

int main() {

    unsigned int in_i, in_j;
    unsigned int min_num, max_num;
    while(cin >> in_i >> in_j) {

        cout << in_i << " " << in_j << " " << get_res(min(in_i, in_j), max(in_i, in_j)) << endl;
    }

    return 0;
}