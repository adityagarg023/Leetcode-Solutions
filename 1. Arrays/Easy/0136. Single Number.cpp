// File: single_number.cpp
// Description: Solution to find the single number in an array where others appear twice
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the number that appears exactly once in the array
     * All other numbers appear exactly twice
     * @param nums Vector of integers
     * @return The single number
     */
    int singleNumber(vector<int>& nums) {
        int result = nums[0];  // Initialize with first element
        
        // XOR all elements to find single number
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        
        return result;
    }
};
