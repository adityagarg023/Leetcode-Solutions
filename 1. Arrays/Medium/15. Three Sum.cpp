// File: three_sum.cpp
// Description: Solution to find all unique triplets summing to zero
// Time Complexity: O(n^2), where n is the length of the input array
// Space Complexity: O(1) excluding output space (or O(n) depending on sorting implementation)

#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    /**
     * Finds all unique triplets in the array that sum to zero
     * @param nums Vector of integers
     * @return Vector of vectors containing triplets that sum to zero
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        // Fix first element and use two pointers for remaining two
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;        // Left pointer
            int right = nums.size() - 1;  // Right pointer
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    // Sum too small, increment left pointer
                    left++;
                }
                else {
                    // Sum too large, decrement right pointer
                    right--;
                }
            }
        }
        
        return result;
    }
};
