// File: find_missing_repeated.cpp
// Description: Solution to find repeated and missing numbers in a grid
// Time Complexity: O(n^2), where n is the grid dimension
// Space Complexity: O(n^2) for the counting array

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the repeated and missing numbers in an n x n grid
     * Grid contains numbers from 1 to n^2 with one number repeated and one missing
     * @param grid 2D vector of integers
     * @return Vector containing [repeated number, missing number]
     */
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();           // Grid dimension
        int totalLength = n * n;       // Total numbers in grid
        vector<int> count(totalLength + 1, 0);  // Count occurrences of each number
        
        // Count occurrences of each number in grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }
        
        int repeated = 0;  // Number that appears twice
        int missing = 0;   // Number that appears zero times
        
        // Find repeated and missing numbers
        for (int i = 1; i <= totalLength; i++) {
            if (count[i] == 2) {
                repeated = i;
            }
            if (count[i] == 0) {
                missing = i;
            }
        }
        
        return {repeated, missing};
    }
};
