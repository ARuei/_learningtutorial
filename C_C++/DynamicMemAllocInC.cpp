#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

/*
	malloc:  void* malloc(size_t size)
	calloc:  void* calloc(size_t num, size_t size)
	realloc: void* realloc(void* ptr, size_t size)
 */

	int inNum;
	cout << "Enter size of input array\n";
	cin >> inNum;

	int *arr = (int *)malloc(inNum*sizeof(int));
	// int *arr = (int *)calloc(inNum, sizeof(int)); -> all initialize to zero

	for (int i=0; i<inNum; i++) {

		arr[i] = i + 1;
	}
	/*
		int *arr = (int *)realloc(A, 0); 
		    -> which is equivalent to free(A)
		int *arr2 = (int *)realloc(NULL, n*sizeof(int)); 
		    -> which is equivalent malloc and it doesn't copy anything from any block
	 */
	int *arr2 = (int *)realloc(arr, 2*inNum*sizeof(int));
	cout << "Previous begining address is: " << arr
		<< "\nPresent begining address is: " << arr2 << endl;

	for (int i=0; i<2*inNum; i++) {

		cout << arr2[i] << endl;
	}
}