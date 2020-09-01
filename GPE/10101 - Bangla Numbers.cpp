#include <iostream>
#include <iomanip>

using namespace std;
             
#define KUTI 10000000
#define LAKH 100000
#define HAJAR 1000
#define SHATA 100

void get_converted(long long num) {

    if (num==0)  {
    
        return;
    }
    if (num/KUTI) {

        get_converted(num/KUTI);
        cout << " kuti";
        num = num % KUTI;
    }

    if (num/LAKH) {

        get_converted(num/LAKH);
        cout << " lakh";
        num = num % LAKH;
    }

    if (num/HAJAR) {

        get_converted(num/HAJAR);
        cout << " hajar";
        num = num % HAJAR;
    }

    if (num/SHATA) {

        get_converted(num/SHATA);
        cout << " shata";
        num = num % SHATA;
    }

    if (num) {

        cout << " " << num;
    }
}

int main() {

    long long num;
    int index=1;
    while (cin>>num) {

        cout << setw(4) << index << ".";
        if (num)  
            get_converted(num);
        else 
            cout << " 0";

        cout << "\n";
        ++index;
    }   

    return 0; 
}