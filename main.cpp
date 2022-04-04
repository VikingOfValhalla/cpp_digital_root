#include <iostream>
#include <vector>
#include <string>

/*
 TODO: use the character count to count if returned 
 additive_summation > 1 continue counting 
*/

class additive_persistence
{
	// initializing variables
	public:
		int Initial_input;
		std::string string_value;
		std::vector <int> vector_of_digits;


	// class constructor
	additive_persistence(int initial_input)
	{
		Initial_input = initial_input;
	};


	// class method
	void calculate_additive_persistence()
	{
		// converting input to string to enumerate each digit
		string_value = std::to_string(Initial_input);

		// iterating through each character in string_value
		for (char& x : string_value)
		{
			// converts x into ASCII 
			// -48 turns back into character equivilent
			int num = x-48;

			// putting each integer digit in vector for enumeration	
			vector_of_digits.push_back(num);
		}

		// TODO HERE 1
		// for loop to count how many digits
		// NOT SURE IF I NEED THIS YET		
		for (std::string::size_type x=0; x < string_value.length(); x++)
		{
			int count = x+1;
			std::cout << count;
		}

		std::cout << std::endl;

		// TODO HERE 2
		// count talley for addition of integers
		int additive_summation = 0;

		for (int x : vector_of_digits)
		{
			additive_summation = additive_summation + x;
		}


		// printing out completed sum
		std::cout << additive_summation << std::endl;
		
	};


};


int main ()
{
	// initializing input variable
	int x;
	std::cout << "Initial Input: ";
	std::cin >> x; 

	// initializing class method and argument as input variable
	additive_persistence additive_persistence_of(x);

	additive_persistence_of.calculate_additive_persistence();

}