#include <iostream>
#include <vector>
#include <string>



int main ()
{
    
    std::vector<int> n_values; 
    int l = 0, r = n_values.size(); // left | right pointers    
    int user_input;

    int summation = 0;
    std::string string_input = std::stoi(user_input);
    while (l < r) {
        if (l < r) {
        (int) string_input[l] + (int) string_input[r] + summation;
        l += 1;
        r -= 1; 
        }
    }    
    std::cout << summation << '\n';

    return 0;
}
