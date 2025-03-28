// File: rotate_matrix.cpp
// Description: Solution to rotate a square matrix 90 degrees clockwise in-place
// Time Complexity: O(n^2), where n is the matrix dimension
// Space Complexity: O(1) as it modifies matrix in-place

#include <vector>
#include <algorithm>  // for std::reverse
using namespace std;

class Solution {
public:
    /**
     * Rotates a square matrix 90 degrees clockwise in-place
     * @param matrix n x n 2D vector of integers
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Matrix dimension
        
        // Step 1: Transpose matrix (swap elements across diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
