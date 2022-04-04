#include <iostream>
#include <vector>
#include <string>

/*
TODO: 
- There is a bug with additive persistence count
- There is a bug with digital root for larger numbers
- Initial Input 393900588225 gives incorrect values, need to figure out why
*/

class additive_persistence
{
	// initializing variables
	public:
		int Initial_input;
		std::string string_value;
		std::vector <int> vector_of_digits;
		int additive_persistence_count;


	// class constructor
	additive_persistence(int initial_input)
	{
		Initial_input = initial_input;
	};

	// to count number of characters in string
	// input string, return count
	int count_string(std::string input_string)
	{
		int count = 0;
		for (std::string::size_type x=0; x < input_string.length(); x++)
		{
			count = x+1;
		}
		return count;
	};

	// to add each integer
	// input vector, return sum
	int additive_summation(std::vector<int> vector_input)
	{
		// TODO HERE 2
		// count talley for addition of integers
		int sum = 0;

		for (int x : vector_input)
		{
			sum = sum + x;
		}
		return sum;	
	};
	
	// convert string to int and add to vector
	// input string, convert to int, add int to vector
	void convert_string_to_int(std::string string_input)
	{
		for (char& x : string_input)
		{
			// converts x into ASCII 
			// -48 turns back into character equivilent
			int num = x-48;

			// putting each integer digit in vector for enumeration	
			vector_of_digits.push_back(num);
		}	
	};
	
	// class method
	void calculate_additive_persistence()
	{
		// to count number of summations
		additive_persistence_count = 0;
		// additive_persistence_count = additive_persistence_count + 1;

		// converting input to string to enumerate each digit
		string_value = std::to_string(Initial_input);

		// function call  to count how many digits
		int count = count_string(string_value);

		// converting string to int and adding to vector
		convert_string_to_int(string_value);

		// add each integer
		int add_sum = additive_summation(vector_of_digits);

		// printing out completed sum
		std::cout << "Sum of Initial Input: " << add_sum << std::endl;

		// while count of integers is greater than 1, function calls for additive_summation
		while (count > 1)
		{
			additive_persistence_count = additive_persistence_count + 1;
			string_value = std::to_string(add_sum);
			count = count_string(string_value);
			vector_of_digits.clear();
			convert_string_to_int(string_value);
			add_sum = additive_summation(vector_of_digits);
		}
		std::cout << "Additive Persistence: " << additive_persistence_count << std::endl;
		std::cout << "Digital Root: " << add_sum << std::endl;
	};

};

int main ()
{
	// initializing input variable, asking user for input
	int x;
	std::cout << "Initial Input: ";
	std::cin >> x; 

	// initializing class method and argument as input variable
	additive_persistence additive_persistence_of(x);
	
	// calling function to calculate additive_persistence
	additive_persistence_of.calculate_additive_persistence();

}