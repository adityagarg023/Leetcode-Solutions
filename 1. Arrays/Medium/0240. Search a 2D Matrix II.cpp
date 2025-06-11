// searchMatrix.cpp
// Solution to search for a target value in a sorted 2D matrix
// The matrix is sorted in ascending order row-wise and column-wise
// Uses a search strategy starting from the top-right corner
// Time Complexity: O(m + n), where m is the number of rows and n is the number of columns
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    // Function to search for a target value in a sorted 2D matrix
    // @param matrix: Input 2D vector of integers (sorted)
    // @param target: Value to search for
    // @return: True if target is found, false otherwise
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // Handle empty matrix case
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int row = matrix.size(); // Number of rows
        int col = matrix[0].size(); // Number of columns
        
        // Start from top-right corner
        int i = 0; // Row index
        int j = col - 1; // Column index
        
        // Search while within matrix bounds
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true; // Target found
            } else if (matrix[i][j] > target) {
                j--; // Move left if current element is greater than target
            } else {
                i++; // Move down if current element is less than target
            }
        }
        
        return false; // Target not found
    }
};
