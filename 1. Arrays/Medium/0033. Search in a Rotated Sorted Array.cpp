// Solution to search for a target value in a rotated sorted array
// Uses binary search to find the pivot and then perform binary search in the appropriate half
// Time Complexity: O(log n), where n is the size of the input array
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    // Function to find the pivot index (smallest element) in a rotated sorted array
    // @param nums: Input array of integers
    // @return: Index of the pivot element
    int pivot(std::vector<int>& nums) {
        int s = 0; // Start index
        int e = nums.size() - 1; // End index
        
        // Binary search to find the pivot
        while (s < e) {
            int m = s + (e - s) / 2; // Calculate middle index
            if (nums[m] >= nums[0]) {
                // If middle element is greater than or equal to first element,
                // pivot is in the right half
                s = m + 1;
            } else {
                // Otherwise, pivot is in the left half including middle
                e = m;
            }
        }
        return s; // Return pivot index
    }
    
    // Function to perform binary search in a sorted range
    // @param nums: Input array of integers
    // @param s: Start index of the search range
    // @param e: End index of the search range
    // @param target: Value to search for
    // @return: Index of target if found, -1 otherwise
    int binary(std::vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int m = s + (e - s) / 2; // Calculate middle index
            if (nums[m] == target) {
                return m; // Target found
            } else if (nums[m] < target) {
                // Target is in the right half
                s = m + 1;
            } else {
                // Target is in the left half
                e = m - 1;
            }
        }
        return -1; // Target not found
    }
    
    // Main function to search for a target in a rotated sorted array
    // @param nums: Input array of integers
    // @param target: Value to search for
    // @return: Index of target if found, -1 otherwise
    int search(std::vector<int>& nums, int target) {
        // Handle empty array case
        if (nums.empty()) {
            return -1;
        }
        
        // Find pivot index
        int p = pivot(nums);
        
        // Decide which half to search based on target value
        if (nums[p] <= target && target <= nums[nums.size() - 1]) {
            // Search in the right half (from pivot to end)
            return binary(nums, p, nums.size() - 1, target);
        } else {
            // Search in the left half (from start to pivot-1)
            return binary(nums, 0, p - 1, target);
        }
    }
};
