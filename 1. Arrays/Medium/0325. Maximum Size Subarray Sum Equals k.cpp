// File: max_subarray_len.cpp
// Description: Solution to find longest subarray with sum equal to k
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(n) for the hash map

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * Finds the length of the longest subarray with sum equal to k
     * @param nums Vector of integers
     * @param k Target sum
     * @return Length of longest subarray with sum k, or 0 if none exists
     */
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;  // Maps prefix sum to earliest index
        prefixMap[0] = -1;                  // Handle subarrays starting from index 0
        
        int prefixSum = 0;                  // Running prefix sum
        int maxLength = 0;                  // Maximum subarray length found
        
        // Iterate through array
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            
            // Check if (prefixSum - k) exists to form subarray with sum k
            if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
                maxLength = max(maxLength, i - prefixMap[prefixSum - k]);
            }
            
            // Store earliest occurrence of prefix sum
            if (prefixMap.find(prefixSum) == prefixMap.end()) {
                prefixMap[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};
