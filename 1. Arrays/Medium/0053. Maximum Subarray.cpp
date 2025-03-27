// File: max_subarray.cpp
// Description: Solution to find maximum subarray sum (Kadane's Algorithm)
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
#include <climits>  // for INT_MIN
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum sum of any contiguous subarray
     * @param nums Vector of integers
     * @return Maximum subarray sum
     */
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        // Handle empty array case
        if (size == 0) {
            return 0;
        }
        
        int currentSum = 0;    // Current running sum
        int maxSum = INT_MIN;  // Maximum sum found so far
        
        // Kadane's Algorithm: Single pass through array
        for (int i = 0; i < size; i++) {
            currentSum += nums[i];
            
            // Update maximum if current sum is greater
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            // Reset sum to 0 if it becomes negative
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};
