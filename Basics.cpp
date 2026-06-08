#include <iostream>
using namespace std;

int main() 
{
	cout << "Ravindra, Let's work on Bitwise Operators now !" << endl;
	cout << "Bitwise Operators work on bits and perform bit by bit operation." << endl << endl;

	// Example of Bitwise AND operator
	int a = 5;      // In binary: 0101
	int b = 3;      // In binary: 0011

	int andResult = a & b; // Result: 0001 (1 in decimal)
	cout << "Bitwise AND of " << a << " & " << b << " = " << andResult << endl << endl;

	// Example of Bitwise OR operator
	int orResult = a | b;  // Result: 0111 (7 in decimal)
	cout << "Bitwise OR of " << a << " | " << b << " = " << orResult << endl << endl;

	// Example of Bitwise XOR operator
	int xorResult = a ^ b; // Result: 0110 (6 in decimal)
	cout << "Bitwise XOR of " << a << " ^ " << b << " = " << xorResult << endl << endl;

	// Example of Bitwise NOT operator
	int notResult = ~a;    // Result: 1010 (in 4 bits, -6 in decimal)
	cout << "Bitwise NOT of " << a << " = " << notResult << endl << endl;

	// Example of Left Shift operator
	int leftShiftResult = a << 1; // Result: 1010 (10 in decimal)
	cout << "Left Shift of " << a << " << 1 = " << leftShiftResult << endl << endl;

	// Example of Right Shift operator
	int rightShiftResult = a >> 1; // Result: 0010 (2 in decimal)
	cout << "Right Shift of " << a << " >> 1 = " << rightShiftResult << endl << endl;

	return 0;
}