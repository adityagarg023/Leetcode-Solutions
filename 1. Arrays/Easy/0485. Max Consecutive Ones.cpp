// File: max_consecutive_ones.cpp
// Description: Solution to find maximum consecutive ones in a binary array
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum number of consecutive 1s in a binary array
     * @param nums Vector of binary integers (0s and 1s)
     * @return Maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();         // Array size
        int currentCount = 0;           // Current streak of 1s
        int maxCount = 0;               // Maximum streak found
        
        // Iterate through array
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                currentCount++;         // Increment current streak
                if (currentCount > maxCount) {
                    maxCount = currentCount;  // Update max if current is larger
                }
            } else {
                currentCount = 0;       // Reset streak on encountering 0
            }
        }
        
        return maxCount;
    }
};
