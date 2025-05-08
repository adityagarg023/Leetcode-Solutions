// File: pivot_index.cpp
// Description: Solution to find pivot index where left and right sums are equal
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the pivot index where sum of left elements equals sum of right elements
     * @param nums Vector of integers
     * @return Pivot index, or -1 if no such index exists
     */
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;  // Total sum of all elements
        // Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;  // Sum of elements to the left of current index
        
        // Check each index as potential pivot
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];  // Sum of elements to the right
            if (leftSum == rightSum) {
                return i;  // Found pivot index
            }
            leftSum += nums[i];  // Update left sum for next iteration
        }
        
        return -1;  // No pivot index found
    }
};
