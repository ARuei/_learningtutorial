#include <iostream>

using namespace std;


int main() {

// arr[i][j] = *(arr[i]+j)
//           = *(*(arr+i)+j)

	int arr[2][3] = {{1, 2, 3},
					{4, 5, 6}};

	cout << arr << " " << &arr[0] << endl;
	cout << *arr << " " << arr[0] << endl; // &arr[0][0]

	cout << arr+1 << " " << &arr[1] << endl;
	cout << *(arr+1) << " " << arr[1] << endl; // arr[1][0]

	cout << *(arr+1)+2 << " " << arr[1]+2 << endl; // &arr[1][2]

	cout << *(*arr+1) << endl;

	return 0;

}