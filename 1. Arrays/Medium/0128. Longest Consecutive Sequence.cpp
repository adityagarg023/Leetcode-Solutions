// longestConsecutive.cpp
// Solution to find the length of the longest consecutive sequence in an unsorted array
// Uses an unordered set for O(1) lookups and processes only the start of sequences
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(n) for the unordered set

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // Function to find the length of the longest consecutive sequence
    // @param nums: Input array of integers
    // @return: Length of the longest consecutive sequence
    int longestConsecutive(std::vector<int>& nums) {
        // Initialize an unordered set with all numbers for O(1) lookups
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longestStreak = 0; // Track the longest sequence found
        
        // Iterate through each number in the set
        for (int num : numSet) {
            // Process only if the number is the start of a sequence
            // (i.e., num-1 is not in the set)
            if (!numSet.count(num - 1)) {
                int currentNum = num; // Current number in sequence
                int currentStreak = 1; // Length of current sequence
                
                // Extend the sequence by checking consecutive numbers
                while (numSet.count(currentNum + 1)) {
                    currentNum++; // Move to next number
                    currentStreak++; // Increment sequence length
                }
                
                // Update longest streak if current streak is longer
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
