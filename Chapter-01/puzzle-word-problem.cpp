#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Extracts words from the grid in a specific direction starting from a given position
 * 
 * This function traverses the grid from a starting position (row, column) in a direction
 * specified by (updateRow, updateColumn). It builds strings character by character and
 * checks if each accumulated string exists in the word list.
 * 
 * @param grid 2D character grid to search through
 * @param wordList List of valid words to match against
 * @param words Vector to store found words (modified by reference)
 * @param row Starting row position (default: 0)
 * @param column Starting column position (default: 0)
 * @param updateRow Row increment for direction (-1, 0, or 1)
 * @param updateColumn Column increment for direction (-1, 0, or 1)
 * 
 * @note The function searches in 8 possible directions:
 *       - Diagonal: (-1,-1), (1,1), (-1,1), (1,-1)
 *       - Vertical: (-1,0), (1,0)
 *       - Horizontal: (0,-1), (0,1)
 */
void getWords(const vector<vector<char>> &grid, const vector<string>& wordList, 
              vector<string>& words, int row = 0, int column = 0, 
              int updateRow = 0, int updateColumn = 0)
{
    string temp = "";
    
    // Traverse the grid in the specified direction until out of bounds
    while (row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size())
    {
        // Append current character to the temporary string
        temp.push_back(grid[row][column]);
        
        // Move to the next position in the specified direction
        row += updateRow;
        column += updateColumn;
        
        // Check if the accumulated string matches any word in the word list
        if (find(wordList.begin(), wordList.end(), temp) != wordList.end())
            words.push_back(temp);
    }
}

/**
 * @brief Finds all words from the word list that exist in the grid
 * 
 * This function searches for words in all 8 directions (horizontal, vertical, and diagonal)
 * starting from every position in the grid. Words can be formed by consecutive characters
 * in any of these directions.
 * 
 * @param grid 2D character grid representing the word search puzzle
 * @param wordList List of words to search for in the grid
 * @return vector<string> Collection of all words found in the grid
 * 
 * @note Duplicate words may appear in the result if they exist in multiple locations
 * @note The search is case-sensitive and matches exact sequences
 */
vector<string> puzzleWords(const vector<vector<char>> &grid, const vector<string>& wordList)
{
    vector<string> words;
    
    // Iterate through every cell in the grid as a potential starting point
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            // Direction vectors for 8 possible directions:
            // di[0],dj[0]: diagonal down-right (1,1)
            // di[1],dj[1]: diagonal up-left (-1,-1)
            // di[2],dj[2]: diagonal up-right (-1,1)
            // di[3],dj[3]: diagonal down-left (1,-1)
            // di[4],dj[4]: vertical up (-1,0)
            // di[5],dj[5]: vertical down (1,0)
            // di[6],dj[6]: horizontal left (0,-1)
            // di[7],dj[7]: horizontal right (0,1)
            const int di[] = {1, -1, -1, 1, -1, 1, 0, 0};
            const int dj[] = {1, -1, 1, -1, 0, 0, -1, 1};
            
            // Search in all 8 directions from the current position
            for (int x = 0; x < 8; x++)
                getWords(grid, wordList, words, i, j, di[x], dj[x]);
        }
    }
    return words; 
}

/**
 * @brief Main function demonstrating word search puzzle solver
 * 
 * Creates a sample 4x4 character grid and searches for specified words
 * in all directions. Prints all found words to standard output.
 * 
 * @return int Exit status (0 for success)
 */
int main(void)
{
    // Sample 4x4 grid representing the word search puzzle
    const vector<vector<char>> grid = {
        {'t', 'h', 'i', 's'}, 
        {'w', 'a', 't', 's'}, 
        {'o', 'a', 'h', 'g'}, 
        {'f', 'g', 'd', 't'}
    };
    
    // List of words to search for in the grid
    const vector<string> wordsList = {"two", "fat", "that"};
    
    // Find all words from the list that exist in the grid
    const vector<string> words = puzzleWords(grid, wordsList);
    
    // Output each found word
    for (auto& word : words)
    {
        cout << word << endl;
    }
    
    return 0;
}

/**
 * @brief Direction increments for grid traversal
 * 
 * Table demonstrates the row and column updates used in the while loop
 * for traversing the grid in different directions:
 * 
 * ----------------------------------------------------
 * |    Diagonal    |    Vertical    |   Horizontal   |
 * ----------------------------------------------------
 * |d(row)|d(column)|d(row)|d(column)|d(row)|d(column)|
 * |------|---------|------|---------|------|---------|
 * |-1    |-1       |-1    |0        |0     |-1       |
 * |1     |1        |1     |0        |0     |1        |
 * |-1    |1        |-     |-        |-     |-        |
 * |1     |-1       |-     |-        |-     |-        |
 * ----------------------------------------------------
 * 
 * - Diagonal directions use non-zero values for both row and column
 * - Vertical directions use non-zero row and zero column
 * - Horizontal directions use zero row and non-zero column
 */