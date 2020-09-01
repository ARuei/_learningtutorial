#include<iostream>

using namespace std;

int main() {


	int testNum = 1741; // 0000 0110 1100 1101
	int *p = &testNum;

	cout << "Size of integer is " << sizeof(int);
	cout << "\nAddress = " << p << ", value = " << *p;
	cout << "\nAddress = " << p+1 << ", value = " << *(p+1);

/*
	char *cp;
	cp = (char*)p; // typecasting

	cout << "\nSize of char is " << sizeof(char);
	cout << "\nAddress = " << cp << ", value = " << *cp;
	cout << "\nAddress = " << cp+1 << ", value = " << *(cp+1);
*/

	/* Void pointer */

	void *p0;
	p0 = p;
 
	//cout << "\nAddress = " << p0 << ", value = " << *p0; 
		// not being mapped to a particular datatype so that we can not dereference this particular pointer variable 

	cout << "\nAddress = " << p0 << endl;
	// Only we can get is address

	//cout << "\nAddress = " << p0+1;
		// still impossible

	return 0;
}