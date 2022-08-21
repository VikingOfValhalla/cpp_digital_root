#include <iostream>
#include <string>
#include <vector>

// STEPS:
// [x] take user integer input
// [x] convert integer to string to use size() function
// [x] for loop through converted string
// [x] convert char to int by subtracting 48 of ascii value
// [x] append int to vector
// [x] if size of vector > 1 sum elements
// [x] counter for each vector created to give additive persistence
// [x] digital root should be last vector summed


long long int user_selection(long long int user_input) {
    std::cin >> user_input;
    return user_input;
}


void append_to_vector(std::vector<int> &vector_input, const long long int selected_value) {
    std::string tmp_string = std::to_string(selected_value); // convert to string to use .size()
    for (int it = 0; it < tmp_string.size(); it++) {
        vector_input.push_back((int)tmp_string[it] - 48);    // ASCII numbers start from 48
    }
}


int size_of_vector(std::vector<int> &vector_input) {
    return vector_input.size();
}


long long int sum_of_elements(std::vector<int> &vector_input) {
    long long int summation = 0;
    for (int it = 0; it < vector_input.size(); it++) {
        summation = vector_input[it] + summation;
    }
    return summation;
}


int main ()
{
    
    std::cout << "Please select an integer to calculate: ";
    long long int user_input;
    user_input = user_selection(user_input);        // take user input

    
    std::vector<int> n_values; 
    append_to_vector(n_values, user_input);         // append user input to vector
    

    // while loop to keep track of size of vector
    int additive_persistence = 0;
    long long int digital_root = 0;
    while (n_values.size() > 1) {
        additive_persistence++;
        digital_root = sum_of_elements(n_values);
        n_values.clear();
        append_to_vector(n_values, digital_root);
    }

    std::cout << user_input << " has an additive persistence of: ";
    std::cout << additive_persistence << std::endl; // print additive persistence

    std::cout << "and a digital root of: ";
    std::cout << digital_root  << std::endl;        // print digital root
    
    return 0;
}
