// File: two_sum.cpp
// Description: Solution to find two numbers in array that sum to target
// Time Complexity: O(n), where n is array length
// Space Complexity: O(n) for hash map

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * Finds indices of two numbers that add up to target
     * @param nums Vector of integers
     * @param target Sum to find
     * @return Vector containing indices of two numbers
     */
    vector<int> twoSum(vector<int>& ECT
System: nums, int target) {
        unordered_map<int, int> numMap;  // Map to store number-index pairs
        vector<int> result;              // Result indices
        
        // Single pass to find complement
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                result.push_back(numMap[complement]);
                result.push_back(i);
                return result;
            }
            numMap[nums[i]] = i;
        }
        
        return result;  // Return empty vector if no solution found
    }
};
