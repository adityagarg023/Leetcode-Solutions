// File: next_permutation.cpp
// Description: Solution to generate the next lexicographically greater permutation
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it modifies array in-place

#include <vector>
#include <algorithm>  // for std::swap and std::sort
using namespace std;

class Solution {
public:
    /**
     * Generates the next lexicographically greater permutation of the array
     * If no greater permutation exists, sorts array in ascending order
     * @param nums Vector of integers to permute
     */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n <= 1) {
            return;
        }
        
        int pivot = -1;  // Index where we find first decreasing element
        
        // Step 1: Find first decreasing element from right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // Step 2: If found, find number just larger than pivot to swap
        if (pivot >= 0) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }
            }
        }
        
        // Step 3: Sort the subarray after pivot (or entire array if no pivot)
        sort(nums.begin() + pivot + 1, nums.end());
    }
};
