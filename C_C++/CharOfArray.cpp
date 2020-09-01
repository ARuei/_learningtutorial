#include <iostream>
#include <string.h>

using namespace std;

void print(char *str) {

/* // setting the count of index
	int cnt = 0;
	while(str[cnt]!='\0') {

		cout << str[cnt];
		cnt++;
	}
*/
	
	while(*str!='\0') {

		cout << *str;
		str++;
	}
	cout << endl;
}

int main() {

// string is end with '\0' 
// if we don't add it, and then
// there's sth wrong with the output
	char ori[] = {'R','U','E','i'};
	cout << ori << endl;


	char s[] = {'R','U','E','i','\0'};
	cout << s << endl;

	char rev[] = "RUEI";
	cout << sizeof(rev) << endl; // total is 5 bytes, \0 is included
	cout << strlen(rev) << endl; // total length is 4

// watch out the declare method
// array and pointers are different
// data type that are used in pretty
// similar manner
	char sh[] = "helloworld!";
	char *psh = sh;
	cout << psh << endl;

	psh[0] = 'H'; // psh[0] is equal to *(psh+0)
	cout << psh << endl;

	cout << "\nWe're going to call print func" << endl;
	print(psh);

	return 0;
}