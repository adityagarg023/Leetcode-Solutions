// File: missing_number.cpp
// Description: Solution to find the missing number using XOR
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the missing number in an array containing 0 to n
     * @param nums Vector of n distinct numbers from 0 to n
     * @return The missing number
     */
    int missingNumber(vector<int>& nums) {
        int result = nums.size();  // Initialize with n
        
        // XOR with indices and values
        for (int i = 0; i < nums.size(); i++) {
            result ^= i;        // XOR with index
            result ^= nums[i];  // XOR with value
        }
        
        return result;
    }
};
