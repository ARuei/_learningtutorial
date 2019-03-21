#include<iostream>

using namespace std;

int main() {


	int ori = 10;
	int *p = &ori;
	int **q = &p;
	int ***r = &q;

	cout << "p is " << p << endl;
	cout << "*p is " << *p << endl;
	
	cout << "q is " << q << endl;
	cout << "*q is " << *q << endl;
	cout << "*(*q) is " << *(*q) << endl;

	cout << "r is " << r << endl;	 
	cout << "*r is " << *r << endl;	 
	cout << "*(*r) is " << *(*r) << endl;
	cout << "*(*(*r)) is " << *(*(*r))  << endl;

	// ***r is equal to ori
	// ***r = ***r + ori
	***r += ori; 
	cout << "ori = " << ori << endl;

	// ***r, **q, *p are all equal to ori
	***r = **q + *p + 12;
	cout << "ori = " << ori << endl;
}