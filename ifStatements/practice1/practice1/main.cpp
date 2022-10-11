#include <iostream>

int main()
{
	int x = 5; // x is set to 5
	bool comparisonResult = x == 5; //a bool is true or false. 0 is false and anything else is 1. This line is saying that if x is exactly 5 then comparisonResult is true
	if (comparisonResult) // if statements are true by default and seeing as we know that comparisonResult is true the if statement will run
	{
		std::cout << "Hello World!" << std::endl;
	}
	std::cin.get();
}
// interestingly we could change comparisonResult in the if condition to 0 and it would not run, changing it to 1 or anything else would make it run