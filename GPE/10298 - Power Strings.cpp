#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define N 1000000

using namespace std;

int main () {

    int failure[N+5] = {0};

    string str;
    while (getline(cin, str)) {

        if (str == ".") break;

        memset(failure, 0, sizeof(failure));
        for (int i=1, j=failure[0]=-1; i<str.size(); i++) {

            while (j>=0 && str[j+1]!=str[i]) j = failure[j];
            if (str[j+1]==str[i]) j++;
            failure[i] = j;
        }

        int rep_pattern = str.size() - failure[str.size()-1] - 1;
        cout << (str.size()%rep_pattern==0 ? str.size()/rep_pattern : 1) << endl; 
    }
    return 0;
}


/*
const int limit = 1000005; 
int failure[limit];
 
void getTable(const string &lookup, int leng) {  

    failure[0] = -1;  
    int i = 0, j = -1;  
    while ( i < leng ) {  

        if ( j == -1 || lookup[i] == lookup[j] ) {  

            i++; 
            
            /*
             * Only useful  when T[i] = T[j] := move the basis of the known suffix
             * Or just zero := back to index[0]
             *(/)
            failure[i] = ++j; 
        }
        else {

            j = failure[j];  
        }
    }  
}  
 
int main() {
    
    string str;
    while ( getline(cin, str) ) {

        if (str == ".") break;

        int len = str.size();
	  	getTable(str, len);

        cout << len/(len-failure[len]) << endl;
	}
	return 0;
}
*/