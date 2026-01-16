#include <iostream>
using namespace std;

/**
 * @brief Counts the number of 1s in the binary representation of a number
 * 
 * This function recursively counts how many bits are set to 1 in the
 * binary representation of the given positive integer.
 * 
 * @param number The positive integer to analyze
 * @return int The count of 1s in the binary representation
 * 
 * @note Base case: when number is 1, returns 1
 * @note Recursive case: divides by 2 and adds 1 if the number is odd
 * 
 * @example binaryOnes(15) returns 4 (binary: 1111)
 * @example binaryOnes(8) returns 1 (binary: 1000)
 */
int binaryOnes(int number)
{
    if (number == 1)
        return 1;
    else if (number % 2 == 0)
        return binaryOnes(number / 2);
    else 
        return binaryOnes(number / 2) + 1;
}

/**
 * @brief Main function to demonstrate binaryOnes
 * 
 * Tests the binaryOnes function with the value 15 and prints the result.
 * 
 * @return int Exit status (0 for success)
 */
int main(void)
{
    cout << binaryOnes(15) << endl;
    return 0;
}