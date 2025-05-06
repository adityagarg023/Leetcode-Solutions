// File: contains_duplicate.cpp
// Description: Solution to check if an array contains any duplicate elements
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(n) for the hash set

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * Checks if the array contains any duplicate elements
     * @param nums Vector of integers
     * @return True if any value appears at least twice, false otherwise
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  // Set to store seen numbers
        
        // Check each number
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;  // Duplicate found
            }
            seen.insert(num);
        }
        
        return false;  // No duplicates found
    }
};
