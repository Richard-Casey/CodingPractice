#include <iostream>
#include "stdlib.h"

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++) // this declares a new variable called i - it will then immedieatly check if i < 5 is a true statement and if so run the body.
	{							// the i++ will then increment the value of i by 1 and then check it all again until i is not less than 5.
		cout << "Hello World!" << endl;
	}
	

	cin.get();
}