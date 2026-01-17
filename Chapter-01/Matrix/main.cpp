#include <iostream>
#include "Matrix.h"
using namespace std;

int main(void)
{
    vector<vector<int>> mtx = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> matrix(mtx);
    matrix.resize(2, 2);
    for (int i = 0; i < matrix.numRows(); i++)
    {
        for (int j = 0; j < matrix.numCols(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    return 0;
}