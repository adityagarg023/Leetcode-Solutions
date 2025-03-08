// File: sort_colors.cpp
// Description: Solution to sort array of 0s, 1s, and 2s in-place (Dutch National Flag problem)
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it sorts in-place

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Sorts an array containing only 0s, 1s, and 2s in-place
     * Uses Dutch National Flag algorithm with three pointers
     * @param nums Vector containing integers 0, 1, and 2
     */
    void sortColors(vector<int>& nums) {
        int low = 0;          // Points to rightmost boundary of 0s
        int mid = 0;          // Current element being processed
        int high = nums.size() - 1;  // Points to leftmost boundary of 2s
        
        // Process elements until mid pointer crosses high pointer
        while (mid <= high) {
            if (nums[mid] == 0) {
                // If current element is 0, swap with element at low pointer
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // If current element is 1, just move mid pointer
                mid++;
            }
            else {
                // If current element is 2, swap with element at high pointer
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
