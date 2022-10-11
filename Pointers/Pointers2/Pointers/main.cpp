#include <iostream>

int main()
{
	int var = 8;
	int* ptr = &var; 
	*ptr = 10;
	std::cout << var << std::endl;
	std::cin.get();  
}

