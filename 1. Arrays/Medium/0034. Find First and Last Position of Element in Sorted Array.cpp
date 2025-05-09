// Solution to find the first and last positions of a target value in a sorted array
// Uses binary search to locate the first and last occurrences efficiently
// Time Complexity: O(log n), where n is the size of the input array
// Space Complexity: O(1), excluding the space needed for output

#include <vector>

class Solution {
public:
    // Function to find the first occurrence of the target in a sorted array
    // @param nums: Input array of integers (sorted)
    // @param target: Value to search for
    // @return: Index of the first occurrence, or -1 if not found
    int firstocc(std::vector<int>& nums, int target) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index
        int ans = -1; // Store result
        
        // Binary search for first occurrence
        while (s <= e) {
            int m = s + (e - s) / 2; // Calculate middle index
            if (nums[m] == target) {
                ans = m; // Update result
                e = m - 1; // Continue searching in the left half
            } else if (nums[m] < target) {
                s = m + 1; // Search in the right half
            } else {
                e = m - 1; // Search in the left half
            }
        }
        return ans;
    }
    
    // Function to find the last occurrence of the target in a sorted array
    // @param nums: Input array of integers (sorted)
    // @param target: Value to search for
    // @return: Index of the last occurrence, or -1 if not found
    int lastocc(std::vector<int>& nums, int target) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index
        int ans = -1; // Store result
        
        // Binary search for last occurrence
        while (s <= e) {
            int m = s + (e - s) / 2; // Calculate middle index
            if (nums[m] == target) {
                ans = m; // Update result
                s = m + 1; // Continue searching in the right half
            } else if (nums[m] < target) {
                s = m + 1; // Search in the right half
            } else {
                e = m - 1; // Search in the left half
            }
        }
        return ans;
    }
    
    // Main function to find the range of the target in a sorted array
    // @param nums: Input array of integers (sorted)
    // @param target: Value to search for
    // @return: Vector containing the first and last positions of the target
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> ans; // Initialize result vector
        
        // Find and store first and last occurrences
        ans.push_back(firstocc(nums, target));
        ans.push_back(lastocc(nums, target));
        
        return ans;
    }
};
