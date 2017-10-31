#include <iostream>

using namespace std;

/*
 *	Function pointers can be passed as argu to functions
 */ 

void PRINT() {

	cout << "HEY,THERE!" << endl;
}

void PTR(void (*ptr)()) {
// function pointer as argu

	ptr(); // callback function that 'ptr' points to
}

int main() {

/*
 *	When reference to a func is passed to another func,
 *	then that particular func is called a CALLBACK func
 */
	// void (*p)() = &PRINT; 
	// PTR(p);
	// -> which are not really needed, instead we use...
	PTR(&PRINT); // PRINT is callback func
}