// majorityElement.cpp
// Solution to find all elements that appear more than ⌊n/3⌋ times in an array
// Uses a hash map to count occurrences of each element
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(n) for the hash map

#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to find all elements appearing more than ⌊n/3⌋ times
    // @param nums: Input array of integers
    // @return: Vector containing elements that appear more than ⌊n/3⌋ times
    std::vector<int> majorityElement(std::vector<int>& nums) {
        // Initialize result vector
        std::vector<int> ans;
        
        // Handle empty array case
        if (nums.empty()) return ans;
        
        // Initialize hash map to store element counts
        std::unordered_map<int, int> map;
        
        // Get size of input array
        int n = nums.size();
        
        // Count occurrences of each element
        for (int num : nums) {
            map[num]++;
        }
        
        // Check for elements with count > ⌊n/3⌋
        for (const auto& pair : map) {
            if (pair.second > n / 3) {
                ans.push_back(pair.first);
            }
        }
        
        return ans;
    }
};
