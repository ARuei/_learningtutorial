#include <iostream>

using namespace std;

int Sum(int arr[], int size) { 
// arr[] is interpreted as *arr, and just inform that it's an array

	int total = 0;
	for (int i=0;i<size;i++) {

		total += arr[i];
		// arr[i] is *(arr+i)
	}

	return total;
}

int main() {

	int arr[] = {1,2,3,4,5};

	cout << Sum(arr, (int)(sizeof(arr)/sizeof(arr[0]))) << endl;
	// arr can be replaced by &arr[0]
}
