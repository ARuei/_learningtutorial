#include <iostream>

using namespace std;

void printEle(int (*arr)[2][2]) {
// (*arr)[j][k] or arr[][j][k]

	cout << arr[0][1][1] << endl;
}

int main() {

/*

	arr[i][j][k] = *(C[i][j]+k) 
	             = *(*(C[i]+j)+k) 
	             = *(*(*(C+i)+j)+k) 

 */

	int arr[3][2][2] = {

		{ {1,2}, {3,4} },
		{ {5,6}, {7,8} },
		{ {9,10}, {11,12} },
	};

	cout << arr << endl; 
	// arr is type of pointer to 2D array of 2X2
	// return int (*)[2][2]
	
	cout << *arr  << endl; 
	// dereferencing once is giving us pointer to one-dimenstional array

	// return int (*)[2]
	// which is equal to "arr[0]" / "&arr[0][0]"

	cout << *(arr[0][1]+1) << endl;
	// arr[0][1] return int (*)
	// which is equal to arr[0][1][1]

	cout << *(arr[1]+1) << endl;
	// arr[1] returns int (*)[2]
	// which is equal to "arr[1][1]" / "&arr[1][1][0]"

	printEle(arr);
}