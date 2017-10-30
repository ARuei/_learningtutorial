#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

void printSent() {

	cout << "Test Information!" << endl;
}

/*
int *sum(int *x, int *y) {

	int result = *x + *y;
	return &result;
	// the lifetime of local variable exists while it's called
	// as a result, while we're returning to main func even though
	// we still use ptr to point at result, however, we can't guarantee
	// the value at that mem location will not be replaced
}
*/

int *sum(int *x, int *y) {

	int *result = (int*)malloc(sizeof(int));
	*result = *x + *y;
	
	// &result is the address where this pointer has alloc in stack
	// result is the address where this pointer point at in heap area
	return result;
}

int main() {


	int x = 5, y = 10;
	int *ptr = sum(&x,&y);

	printSent();
	cout << *ptr << endl;
}