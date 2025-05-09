// Solution to traverse a 2D matrix in spiral order (clockwise from outer to inner)
// Uses boundary pointers to track the current layer and a counter to track elements
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns
// Space Complexity: O(1), excluding the space needed for output

#include <vector>

class Solution {
public:
    // Function to traverse a matrix in spiral order
    // @param matrix: Input 2D vector of integers
    // @return: Vector containing elements in spiral order
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ans; // Initialize result vector
        
        // Handle empty matrix case
        if (matrix.empty()) return ans;
        
        int row = matrix.size(); // Number of rows
        int col = matrix[0].size(); // Number of columns
        
        // Initialize boundary pointers
        int startRow = 0; // Top boundary
        int startCol = 0; // Left boundary
        int endRow = row - 1; // Bottom boundary
        int endCol = col - 1; // Right boundary
        
        int count = 0; // Count of elements added
        int total = row * col; // Total elements in matrix
        
        // Traverse matrix in spiral order
        while (count < total) {
            // Traverse right (top row)
            for (int index = startCol; count < total && index <= endCol; index++) {
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++; // Move top boundary down
            
            // Traverse down (right column)
            for (int index = startRow; count < total && index <= endRow; index++) {
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--; // Move right boundary left
            
            // Traverse left (bottom row)
            for (int index = endCol; count < total && index >= startCol; index--) {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--; // Move bottom boundary up
            
            // Traverse up (left column)
            for (int index = endRow; count < total && index >= startRow; index--) {
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++; // Move left boundary right
        }
        
        return ans;
    }
};
