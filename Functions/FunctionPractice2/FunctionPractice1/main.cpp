#include <iostream>

int multiply(int a, int b) // function created to handle the value of 'a' mnultiplied by 'b'
{
	return a * b;
}

int main()
{
	int result = multiply(4, 5);			// called on the multiply function and given the int a and int b in parameters to multiply as per the fuction
	std::cout << result << std::endl;		// printed the result to the console (which should be 20

	int result2 = multiply(30, 3);			// the variable created to hold the result has changed name 	
	std::cout << result2 << std::endl;		// other wise 'result' will only print the first sum to the console (which is 20 and not 90)

	int result3 = multiply(7, 3);			//3 sums totalling 20, 90 and 21. if cout << result was used it would only print the variable hel in result
	std::cout << result3 << std::endl;

}

// this can be even simplier!