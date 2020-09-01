#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

int findMissingNum(int arr[], int brr[], int n, int m) {

    map<int, int> numMap;

    for (int i=0; i<m; i++) {

        numMap[brr[i]]++;
    }

    for (int i=0; i<n; i++) {

        if (numMap.find(arr[i]) == numMap.end()) {
            return arr[i];
        }
        if (numMap[arr[i]]==0) {
            return arr[i];
        }

        numMap[arr[i]]--;
    }

}

int main () {

    int m, n, len_a, len_b;

    cin >> m >> n;
    
    int * arr = new int [n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }   

    m--;
    len_a = n;
    while (m-- && n--) {

        len_b = n;

        int * brr = new int[n];
        for (int i=0; i<n; i++) {
            scanf("%d", &brr[i]);
        }

        /*cout << len_a << "  |  " << len_b << endl;*/
        int res = findMissingNum(arr, brr, len_a, len_b);
        cout << res << endl;

        memset(arr, -1, len_a);
        
        for (int i=0; i<len_b; i++) {
            arr[i] = brr[i];
        }

        len_a = len_b;
        
        delete [] brr;
    }

    delete [] arr;
    
    return 0;
}