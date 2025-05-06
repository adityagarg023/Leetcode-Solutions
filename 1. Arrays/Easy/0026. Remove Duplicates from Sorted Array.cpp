// File: remove_duplicates.cpp
// Description: Solution to remove duplicates from sorted array in-place
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it modifies array in-place

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Removes duplicates from sorted array in-place and returns new length
     * @param nums Sorted vector of integers
     * @return Length of array with duplicates removed
     */
    int removeDuplicates(vector<int>& nums) {
        // Handle empty array case
        if (nums.empty()) {
            return 0;
        }
        
        int uniquePtr = 0;  // Points to position for next unique element
        
        // Iterate through array, keeping unique elements
        for (int current = 1; current < nums.size(); ++current) {
            if (nums[current] != nums[uniquePtr]) {
                ++uniquePtr;
                nums[uniquePtr] = nums[current];
            }
        }
        
        return uniquePtr + 1;  // Return length of unique elements
    }
};
