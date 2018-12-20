#include <iostream>

using namespace std;

int calc_cycle_len(int);
int get_res(int, int);

int main() {

    unsigned int in_i, in_j, tmp_i, tmp_j;
    while(cin >> in_i >> in_j) {

        tmp_i = in_i;
        tmp_j = in_j;

        int min_num = min( in_i, in_j);
        int max_num = max( in_i, in_j);

        cout << tmp_i << " " << tmp_j << " " << get_res(min_num, max_num) << endl;
    }

    return 0;
}

int calc_cycle_len(int in) {

    int cycle_len = 1;
    while(in!=1) {

        if(in%2) {

            in = 3*in + 1;
            in = in >> 1;
            cycle_len+=2;
        }
        else {

            in = in >> 1;
            cycle_len++;
        }
    }

    return cycle_len;
}

int get_res(int lower, int upper) {

    int res=0, tmp_res;

    for (int i=lower; i<=upper; i++) {

        tmp_res = calc_cycle_len(i);

        if (res < tmp_res) {

            res = tmp_res;
        }
    }

    return res;
}

