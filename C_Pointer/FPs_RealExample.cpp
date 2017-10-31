#include <iostream>
#include <cmath>

using namespace std;

int cmp(int x, int y) {

	if (x>y) return 1;
	else return -1;
}

int abscmp(int x, int y) {

	if (abs(x) > abs(y)) return 1;
	else return -1;
}

/*
 *	Callback func should compare two integers, and...
 *  return 1 if first element has higher rank
 *  return -1 is second has higher rank
 */
void BubbleSort(int *arr, int size, int (*cmp)(int, int)) {

	int tmp;

	for (int i=0; i<size; i++) {

		for (int j=0; j<size-1; j++) {

			if (cmp(arr[j], arr[j+1]) > 0) {

				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= tmp;
			}
		}
	}
}

void OriginalBubbleSort(int *arr, int size) {

	int tmp;

	for (int i=0; i<size; i++) {

		for (int j=0; j<size-1; j++) {

			if (arr[j]>arr[j+1]) {

				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= tmp;
			}
		}
	}
}

void PRINT(int *arr, int size) {

	for (int i=0; i<6; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {


	int A[] = {-2,3,-4,6,-1,5};
	BubbleSort(A, 6, cmp);
	PRINT(A, 6);

/*
 * The bubble sort takes the argument (A, 6, abscmp), So the int (*cmp)(int, int) declared
 * inside the void BubbleSort(int *A, int n, int (*cmp)(int, int)) points to abscmp function
 * instead of the cmp function.

 * Even if we changed the cmp inside BubbleSort to another name just like
 * int (*ptr)(int, int)) it would work fine. 
 */
	BubbleSort(A, 6, abscmp); //
	PRINT(A, 6);

	return 0;
}