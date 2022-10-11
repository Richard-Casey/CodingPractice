#include <iostream>

int main()
{
	int var = 8;
	void* ptr = &var; // the ampersnad (&) in front of the variable is basically asking "Hey, what is your memory address?"
	std::cin.get();   // and then assigning that address to our variable ptr
}

// setting a break point on line 7 and then running in debug mode will show that the value of ptr is now a memory address.