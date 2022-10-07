#include <iostream>

int multiply(int a, int b) // function created to handle the value of 'a' mnultiplied by 'b'
{
	return a * b;
}

void multiplyAndLog(int a, int b)		// created another function called multiplyAndLog that incorporates the first function multiply
{										// its been given int a and int b
	int result = multiply(a, b);		// these are the same two int's specified in line 3
	std::cout << result << std::endl;
}

int main()
{
	multiplyAndLog(11, 2);		// given two int's as specified in line 8
	multiplyAndLog(7, 7);
	multiplyAndLog(9, 4);
	
}

// this will print 22, 49 and 36