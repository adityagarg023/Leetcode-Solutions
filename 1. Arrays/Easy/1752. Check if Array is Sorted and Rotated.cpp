// File: check_sorted_rotated.cpp
// Description: Solution to check if array is sorted and rotated
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Checks if array is sorted and possibly rotated
     * @param nums Vector of integers
     * @return True if array is sorted and rotated, false otherwise
     */
    bool check(vector<int>& nums) {
        int breakCount = 0;  // Count of breaks in sorted order
        
        // Check breaks in sorted order between adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                breakCount++;
            }
        }
        
        // Check break between last and first element
        if (nums[nums.size() - 1] > nums[0]) {
            breakCount++;
        }
        
        // Array is sorted and rotated if at most one break exists
        return breakCount <= 1;
    }
};
