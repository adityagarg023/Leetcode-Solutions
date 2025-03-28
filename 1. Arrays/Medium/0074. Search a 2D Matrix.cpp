// File: search_matrix.cpp
// Description: Solution to search for a target in a sorted 2D matrix
// Time Complexity: O(log(m*n)), where m and n are matrix dimensions
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Searches for a target value in a sorted 2D matrix
     * Matrix is sorted in ascending order from left to right and top to bottom
     * @param matrix 2D vector of integers
     * @param target Value to search for
     * @return True if target is found, false otherwise
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0;              // Start of search range
        int end = rows * cols - 1;  // End of search range
        
        // Binary search treating matrix as 1D array
        while (start <= end) {
            int mid = start + (end - start) / 2;  // Avoid integer overflow
            int element = matrix[mid / cols][mid % cols];  // Convert 1D index to 2D
            
            if (element == target) {
                return true;
            }
            else if (element < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return false;
    }
};
