#include <iostream>
#include <string>
#include <vector>

// STEPS:
// [x] take user integer input
// [x] convert integer to string to use size() function
// [x] for loop through converted string
// [x] convert char to int by subtracting 48 of ascii value
// [x] append int to vector
// [ ] if size of vector > 1 sum elements
// [ ] counter for each vector created to give additive persistence
// [ ] digital root should be last vector summed


int user_selection(int user_input) {
    std::cin >> user_input;
    return user_input;
}


void append_to_vector(std::vector<int> &vector_input, const int selected_value) {
    std::string tmp_string = std::to_string(selected_value); // convert to string to use .size()
    for (int it = 0; it < tmp_string.size(); it++) {
        vector_input.push_back(t(int)tmp_string[it] - 48); // ASCII numbers start from 48
    }
}


int main ()
{
    
    int user_input;
    user_input = user_selection(user_input); // take user input
    
    std::vector<int> n_values; 
    append_to_vector(n_values, user_input); // append user input to vector
    
    // for printing
    for (int it = 0; it < n_values.size(); it++) {
        std::cout << n_values[it] << '\n';
    }
    
    return 0;
}
