#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {

	int *heapPointer;

/* C */

	heapPointer = (int*)malloc(sizeof(int));
	*heapPointer = 66;

	cout << heapPointer << "   " << *heapPointer << endl;
	free(heapPointer);

	heapPointer = (int*)malloc(20*sizeof(int));	
	free(heapPointer);

/* C++ */

	heapPointer = new int;
	*heapPointer = 99;

	cout << heapPointer << "   " << *heapPointer << endl;
	delete heapPointer;


	heapPointer = new int[20];
	delete[] heapPointer;

	return 0;
}