#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
using namespace std;

/**
 * @class Matrix
 * @brief A templated 2D matrix class.
 * @tparam Object The type of elements stored in the matrix
 */
template<typename Object>
class Matrix
{
private:
    vector<vector<Object>> arr; ///< 2D vector storing matrix elements
    
public:
    /**
     * @brief Constructs a matrix with specified dimensions.
     * @param rows Number of rows
     * @param cols Number of columns
     */
    Matrix(int rows, int cols) : arr{rows}
    {
        for (vector<Object>& row : arr)
            row.resize(cols);
    }

    /**
     * @brief Constructs a matrix from an existing 2D vector (copy).
     * @param matrix The 2D vector to copy
     */
    Matrix(vector<vector<Object>> matrix) : arr{matrix}
    {}

    /**
     * @brief Constructs a matrix from an existing 2D vector (move).
     * @param matrix The 2D vector to move
     */
    Matrix(vector<vector<Object>>&& matrix) : arr{std::move(matrix)}
    {}

    /**
     * @brief Default constructor creates an empty matrix.
     */
    Matrix() : arr{}
    {}

    /**
     * @brief Accesses a row (const version).
     * @param row Row index
     * @return Const reference to the row vector
     */
    const vector<Object>& operator[](int row) const
    {
        return arr[row];
    }

    /**
     * @brief Accesses a row (non-const version).
     * @param row Row index
     * @return Reference to the row vector
     */
    vector<Object>& operator[](int row)
    {
        return arr[row];
    }

    /**
     * @brief Gets the number of rows.
     * @return Number of rows in the matrix
     */
    int numRows() const 
    {
        return arr.size();
    }

    /**
     * @brief Gets the number of columns.
     * @return Number of columns, or 0 if matrix is empty
     */
    int numCols() const 
    {
        return numRows() ? arr[0].size() : 0;
    }

    /**
     * @brief Resizes the matrix to new dimensions.
     * @param rows New number of rows
     * @param cols New number of columns
     */
    void resize(int rows, int cols)
    {
        arr.resize(rows);
        for (vector<Object>& row : arr)
            row.resize(cols);
    }
};
#endif