#include <iostream>

int multiply(int a, int b) // function created to handle the value of 'a' mnultiplied by 'b'
{
	return a * b;
}

int main()
{
	int result = multiply(4, 5);			// called on the multiply function and given the int a and int b in parameters to multiply as per the fuction
	std::cout << result << std::endl;		// printed the result to the console (which should be 20
}