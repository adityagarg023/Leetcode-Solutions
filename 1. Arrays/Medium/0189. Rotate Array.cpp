// rotateArray.cpp
// Solution to rotate an array to the right by k steps
// Uses an auxiliary array to store the rotated elements
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(n) for the auxiliary array

#include <vector>

class Solution {
public:
    // Function to rotate the array to the right by k steps
    // @param nums: Input array of integers
    // @param k: Number of steps to rotate
    void rotate(std::vector<int>& nums, int k) {
        // Handle empty array or no rotation case
        if (nums.empty() || k == 0) return;
        
        int n = nums.size(); // Size of the array
        std::vector<int> ans(n); // Auxiliary array to store rotated elements
        
        // Normalize k to handle cases where k > n
        k = k % n;
        
        // Place each element in its new position after rotation
        for (int i = 0; i < n; i++) {
            ans[(i + k) % n] = nums[i];
        }
        
        // Copy rotated elements back to the original array
        nums = ans;
    }
};
