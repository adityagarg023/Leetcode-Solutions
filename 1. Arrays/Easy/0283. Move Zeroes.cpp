// File: move_zeroes.cpp
// Description: Solution to move all zeroes to end while maintaining relative order
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it modifies array in-place

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Moves all zeroes to the end of array while maintaining relative order of non-zero elements
     * @param nums Vector of integers
     */
    void moveZeroes(vector<int>& nums) {
        int zeroPtr = 0;  // Points to next position for non-zero element
        
        // Move all non-zero elements to the front
        for (int nonzeroPtr = 0; nonzeroPtr < nums.size(); nonzeroPtr++) {
            if (nums[nonzeroPtr] != 0) {
                swap(nums[zeroPtr], nums[nonzeroPtr]);
                zeroPtr++;
            }
        }
    }
};
