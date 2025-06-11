// Solution to rearrange an array such that positive and negative numbers alternate
// Places positive numbers at even indices and negative numbers at odd indices
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(n) for the result array

#include <vector>

class Solution {
public:
    // Function to rearrange array with alternating positive and negative numbers
    // @param nums: Input array of integers with equal number of positive and negative numbers
    // @return: Rearranged array with alternating positive and negative numbers
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        
        // Initialize result array
        std::vector<int> res(n);
        
        // Initialize pointers for positive (even) and negative (odd) indices
        int pos = 0; // For positive numbers (even indices: 0, 2, 4, ...)
        int neg = 1; // For negative numbers (odd indices: 1, 3, 5, ...)
        
        // Iterate through the input array
        for (int num : nums) {
            if (num > 0) {
                // Place positive number at even index
                res[pos] = num;
                pos += 2; // Move to next even index
            } else {
                // Place negative number at odd index
                res[neg] = num;
                neg += 2; // Move to next odd index
            }
        }
        
        return res;
    }
};
