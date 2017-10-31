#include <iostream>
#include <stdlib.h>

using namespace std;

// void pointer is generic pointer, we can
// typecast them to a pointer of any data type
int cmp(const void *a, const void *b) {
/*
 *	The two elements to be compared are being passed
 *	through reference, and their addresses are being 
 *	passed though a pointer
 *
 *	const keyword means here we can't modify the address
 *	in this pointer variable
 */

	// typecasting to int* and getting value
	int A = *((int*)a); 
	int B = *((int*)b);

	return A-B; // returning postivie value means A is ranked higher
				// returning negative value means B is ranked higher
}

int main() {

/*
 *	Remember QSORT can sort any array, not just an interger array
 */
	int arr[] = {-22, 12, -5, 24, -6, 88};
	qsort(arr, 6, sizeof(int), cmp);

	for (int i =0; i<6; i++) {

		cout << arr[i] << " ";  
	}
	cout << endl;

	return 0;
}