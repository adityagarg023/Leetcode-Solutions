// File: majority_element.cpp
// Description: Solution to find the majority element using Boyer-Moore Voting Algorithm
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the majority element that appears more than n/2 times
     * @param nums Vector of integers
     * @return The majority element
     */
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];  // Current candidate for majority
        int count = 1;            // Count of candidate occurrences
        
        // Boyer-Moore Voting Algorithm
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];  // Choose new candidate
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
