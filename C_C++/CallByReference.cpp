#include<iostream>

using namespace std;

/* local variable problem
	void incre(int num) {

		num += 1;
	}

	int main() {


		int num = 10;
		incre(num);

		cout << num << endl;
	}
*/

void incre(int *num) {

	*num += 1;
}

int main() {


	int num = 10;
	incre(&num);

	cout << num << endl;
}
