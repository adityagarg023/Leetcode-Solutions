// subarraySum.cpp
// Solution to find the number of subarrays with sum equal to k
// Uses a hash map to store cumulative sum frequencies for efficient counting
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(n) for the hash map

#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to count subarrays with sum equal to k
    // @param nums: Input array of integers
    // @param k: Target sum for subarrays
    // @return: Number of subarrays with sum equal to k
    int subarraySum(std::vector<int>& nums, int k) {
        // Initialize hash map to store frequency of cumulative sums
        std::unordered_map<int, int> prefixSums;
        
        // Initialize with 0 sum having frequency 1 to handle subarrays starting from index 0
        prefixSums[0] = 1;
        
        int count = 0; // Count of subarrays with sum k
        int sum = 0;   // Current cumulative sum
        
        // Iterate through the array
        for (int num : nums) {
            sum += num; // Update cumulative sum
            
            // If (sum - k) exists in prefixSums, add its frequency to count
            if (prefixSums.count(sum - k)) {
                count += prefixSums[sum - k];
            }
            
            // Increment frequency of current cumulative sum
            prefixSums[sum]++;
        }
        
        return count;
    }
};
