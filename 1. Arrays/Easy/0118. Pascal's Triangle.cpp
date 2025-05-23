// File: pascal_triangle.cpp
// Description: Solution to generate Pascal's Triangle using binomial coefficients
// Time Complexity: O(n^2), where n is the number of rows
// Space Complexity: O(n^2) for the output triangle

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Calculates combination (n choose r) efficiently
     * @param n Total items
     * @param r Items to choose
     * @return Number of combinations
     */
    int nCr(int n, int r) {
        long long result = 1;
        // Optimize by using smaller value of r
        r = min(r, n - r);
        
        // Calculate nCr to avoid overflow
        for (int i = 0; i < r; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        
        return static_cast<int>(result);
    }
    
    /**
     * Generates Pascal's Triangle up to specified number of rows
     * @param numRows Number of rows to generate
     * @return Vector of vectors representing Pascal's Triangle
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        // Handle empty or zero rows case
        if (numRows == 0) {
            return triangle;
        }
        
        // Generate each row
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            // Calculate elements using nCr
            for (int j = 0; j <= i; j++) {
                row.push_back(nCr(i, j));
            }
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
