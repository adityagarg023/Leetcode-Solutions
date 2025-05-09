// Solution to find all unique quadruplets in the array that sum up to the target value
// Uses a two-pointer technique after sorting the input array
// Time Complexity: O(n^3), where n is the size of the input array
// Space Complexity: O(1), excluding the space needed for output

#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to find all unique quadruplets in nums that sum to target
    // @param nums: Input array of integers
    // @param target: Target sum for quadruplets
    // @return: Vector of vectors containing all unique quadruplets
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        // Initialize result vector to store quadruplets
        std::vector<std::vector<int>> ans;
        
        // Get size of input array
        int n = nums.size();
        
        // Sort the array to enable two-pointer technique and handle duplicates
        std::sort(nums.begin(), nums.end());
        
        // Early exit if array is too small
        if (n < 4) return ans;
        
        // Iterate through first number
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            // Iterate through second number
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // Calculate remaining sum needed
                long long remaining = (long long)target - nums[i] - nums[j];
                
                // Initialize two pointers for the remaining pair
                int left = j + 1;
                int right = n - 1;
                
                // Two-pointer technique to find the remaining pair
                while (left < right) {
                    long long twoSum = (long long)nums[left] + nums[right];
                    
                    if (twoSum < remaining) {
                        // Sum is too small, move left pointer
                        ++left;
                    } else if (twoSum > remaining) {
                        // Sum is too large, move right pointer
                        --right;
                    } else {
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for left pointer
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        // Skip duplicates for right pointer
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                            
                        // Move both pointers
                        ++left;
                        --right;
                    }
                }
            }
        }
        
        return ans;
    }
};
