#include <iostream>
using namespace std;

/**
 * @brief Recursively generates all permutations of a string
 * @param str String to permute
 * @param low Starting index
 * @param high Ending index
 */
void permute(const string& str, int low, int high)
{
    if (low > high)
    {
        cout << str << endl;
        return;
    }

    for (int i = low; i <= high; i++)
    {
        string temp = str;
        swap(temp[i], temp[low]);
        permute(temp, low + 1, high);
        swap(temp[i], temp[low]);
    }
}

/**
 * @brief Driver function to print all permutations of a string
 * @param str String to permute
 */
void permute(const string& str)
{
    permute(str, 0, str.size() - 1);
}

/**
 * @brief Main function
 * @return Exit status
 */
int main(void)
{
    permute("abc");
    return 0;
}