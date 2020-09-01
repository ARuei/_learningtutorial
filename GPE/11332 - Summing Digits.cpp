#include <iostream>
#include <memory.h>

using namespace std;

int main () {

    char str[11];
    while(cin>>str) {

        if (str[0] == '0') {
            break;
        }

        while (strlen(str)!=1) {

            int sum=0;
            for (int i=0; i<strlen(str); i++) {
                sum += (str[i] - '0'); 
                // derive the offset started from \0
                // note that the offset is considered as the actual number
            }

            memset(str, '\0', sizeof(str));
            sprintf(str, "%d", sum);
        }

        cout << str << endl;
    }

    return 0;
}