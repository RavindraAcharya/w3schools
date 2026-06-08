#include <iostream>
using namespace std;

int add(int x, int y) {
	return x + y;
}

double add(double x, double y) {
	return x + y;
}

string add(string x, string y) {
	return x + y;
}

int main()
{
	int a = 5, b = 10;
	double c = 5.7, d = 10.5;
	string e = "Hello, ", f = "World!";

	cout << "Integer addition: " << add(a, b) << endl;
	cout << "Double addition: " << add(c, d) << endl;
	cout << "String addition: " << add(e, f) << endl;

	return EXIT_SUCCESS;
}