// Description: Solution to find duplicated and missing numbers using in-place marking
// Time Complexity: O(n), where n is array length
// Space Complexity: O(1) modifying input array

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the duplicated and missing numbers in an array
     * Array contains n numbers from 1 to n with one duplicate and one missing
     * @param nums Vector of integers
     * @return Vector containing [duplicated number, missing number]
     */
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);  // [duplicated, missing]
        int size = nums.size();
        
        // Mark presence by negating elements
        for (int i = 0; i < size; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            } else {
                result[0] = abs(nums[i]);  // Found duplicate
            }
        }
        
        // Find missing number (positive index + 1)
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }
        
        return result;
    }
};
