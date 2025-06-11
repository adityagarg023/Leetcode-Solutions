// Solution to find the maximum frequency of any element possible by modifying the array
// Uses a sliding window approach with a sorted array to maximize frequency within k operations
// Time Complexity: O(n log n) due to sorting, where n is the size of the input array
// Space Complexity: O(1) as it uses constant extra space

#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to find the maximum frequency achievable within k operations
    // @param nums: Input array of integers
    // @param k: Maximum number of operations allowed
    // @return: Maximum frequency of any element possible
    int maxFrequency(std::vector<int>& nums, int k) {
        // Sort the array in ascending order
        std::sort(nums.begin(), nums.end());
        
        long long total = 0; // Sum of elements in the current window
        int left = 0; // Left boundary of the sliding window
        int ans = 0; // Maximum frequency found
        
        // Iterate with right pointer to expand the window
        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right]; // Add current element to window sum
            
            // Shrink window while the cost to make all elements equal to nums[right]
            // exceeds k operations
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left]; // Remove leftmost element from sum
                ++left; // Shrink window from left
            }
            
            // Update maximum frequency if current window size is larger
            ans = std::max(ans, right - left + 1);
        }
        
        return ans;
    }
};
