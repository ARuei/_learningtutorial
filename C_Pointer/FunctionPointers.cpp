#include <iostream>

using namespace std;

int ADD(int x, int y) {

	return x+y;
}


void PRINT(){

	cout << "Hello, this is testing information." << endl;
}

void PRINTS(char *name) {

	cout << name << endl;
}

/*
 *	int *FUNC(int x, int y)  // declaring a function that would return int *
 *	int (*FUNC)(int x, int y) // declaring a function pointer
 *
 */

int main() {

	int (*p)(int, int); // a function pointer that should take (int, int), as argu and return int 
	p = &ADD; // which is same as p = ADD;

	int res; // de-referencing and excuting the function
	res = (*p)(1,2); // Which is same as res = p(1,2);
	cout << res << endl;

	void (*q)() = PRINT;
	q();

	void (*r)(char*) = PRINTS;
	r("Hey, there!");

	return 0;
}