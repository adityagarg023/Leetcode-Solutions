// File: set_matrix_zeroes.cpp
// Description: Solution to set rows and columns to zero where element is zero
// Time Complexity: O(m * n), where m and n are matrix dimensions
// Space Complexity: O(1) using matrix itself as markers

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Sets entire row and column to 0 where an element is 0, in-place
     * @param matrix 2D vector of integers
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();           // Number of rows
        int cols = matrix[0].size();        // Number of columns
        int firstColHasZero = 1;            // Flag for first column
        
        // First pass: Mark rows and columns using first row and column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;        // Mark row
                    if (j != 0) {
                        matrix[0][j] = 0;    // Mark column (except first)
                    } else {
                        firstColHasZero = 0; // Special mark for first column
                    }
                }
            }
        }
        
        // Handle single-row case separately
        if (rows == 1) {
            if (matrix[0][0] == 0 || firstColHasZero == 0) {
                for (int j = 0; j < cols; j++) {
                    matrix[0][j] = 0;
                }
            }
            return;
        }
        
        // Second pass: Set elements to 0 based on markers (skip first row/col)
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        // Handle first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Handle first column if needed
        if (firstColHasZero == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
