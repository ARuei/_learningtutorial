#include <iostream>

using namespace std;

int main() {


	int  A[] = {1,2,3,4,5};

	cout << A << endl << endl;
	for (int i=0;i<(int)(sizeof(A)/sizeof(*A));i++) {


		cout << &A[i] << endl;
		cout << A[i] << endl;
		cout << *(A+i) << endl;
	}

	int *p = A;
	cout << *p << endl;
	p++;
	cout << *p << endl;
}
