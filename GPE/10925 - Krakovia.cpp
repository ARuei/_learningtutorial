#include <iostream>
#include <algorithm>

#define LIMIT 31

using namespace std;

int main() {

    int numOfItems, numOfFriends, cnt = 0;   
    while (cin >> numOfItems >> numOfFriends) {

        if (!numOfItems || !numOfFriends) break;

        getchar();
        string item;
        int sum[LIMIT] = {0};

        for (int i=0; i<numOfItems; i++) {

            getline(cin, item);
            reverse(item.begin(), item.end());

            for (int j=0; j<item.size(); ++j) {

                sum[j] += (item[j] - '0');
            }
        }

        for (int j=0; j<LIMIT; ++j) {

            if (sum[j]>=10) {

                sum[j+1] += sum[j] / 10;
                sum[j] %= 10;
            }
        }

        cout << "Bill #" << ++cnt << " costs ";

        int idx=LIMIT;
        while(!sum[--idx] && idx!=-1);
        int temp = idx;
        for (; idx>=0; --idx) {
            
            cout << sum[idx];
        }
        cout << ": each friend should pay ";   

        for (int i = temp; i>=0; i--) {
  
            if (i>0) {
                sum[i-1] += sum[i]%numOfFriends*10;
            }
            sum[i] /= numOfFriends;
        }

        while(!sum[temp] && temp>=0) {
            --temp;
            if (temp<0) {

                cout << 0;
            }
        };
        for (; temp>=0; temp--) 
            cout << sum[temp];
        
        cout << endl << endl;
    }

    return 0;
}