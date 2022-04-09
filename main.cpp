#include <iostream>
#include <vector>
#include <string>

class additive_persistence
{
	// initializing variables
	private:
		unsigned long long int Initial_input;
		std::string string_value;
		std::vector <unsigned long long int> vector_of_digits;
		unsigned long long int additive_persistence_count;

	public:
	// class constructor
	additive_persistence(unsigned long long int initial_input)
	{
		Initial_input = initial_input;
	};

	// to count number of characters in string
	// input string, return count
	unsigned long long int count_string(std::string input_string)
	{
		unsigned long long int count = 0;
		for (std::string::size_type x=0; x < input_string.length(); x++)
		{
			count = x+1;
		}
		return count;
	};

	// to add each integer
	// input vector, return sum
	unsigned long long int additive_summation(std::vector<unsigned long long int> vector_input)
	{
		// count talley for addition of integers
		unsigned long long int sum = 0;

		for (unsigned long long int x : vector_input)
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
			unsigned long long int num = x-48;

			// putting each integer digit in vector for enumeration	
			vector_of_digits.push_back(num);
		}	
	};
	
	// class method
	void calculate_additive_persistence()
	{
		// to count number of summations
		additive_persistence_count = 0;

		// converting input to string to enumerate each digit
		string_value = std::to_string(Initial_input);

		// function call  to count how many digits
		unsigned long long int count = count_string(string_value);

		// converting string to int and adding to vector
		convert_string_to_int(string_value);

		// add each integer
		unsigned long long int add_sum = additive_summation(vector_of_digits);

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
		std::cout << " has an additive persistence of " << additive_persistence_count;
		std::cout << " and a digital root of " << add_sum << std::endl;
	};

};

int main ()
{
	// printing line break only for console formatting
	std::cout << std::endl;

	// initializing input variable, asking user for input
	unsigned long long int x;
	std::cout << "Initial Input: ";
	std::cin >> x; 

	//printing for final output
	std::cout << x;
	
	// initializing class method and argument as input variable
	additive_persistence additive_persistence_of(x);
	
	// calling function to calculate additive_persistence
	additive_persistence_of.calculate_additive_persistence();

	// printing line break only for console formatting
	std::cout << std::endl;

}