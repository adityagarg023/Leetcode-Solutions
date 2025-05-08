// File: unique_occurrences.cpp
// Description: Solution to check if all elements have unique occurrence counts
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(n) for the hash map and hash set

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * Checks if the frequency of each number in the array is unique
     * @param arr Vector of integers
     * @return True if all occurrence counts are unique, false otherwise
     */
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;  // Store frequency of each number
        unordered_set<int> freqSet;       // Store seen frequencies
        
        // Count frequency of each number
        for (int num : arr) {
            freqMap[num]++;
        }
        
        // Check if any frequency is repeated
        for (const auto& [num, count] : freqMap) {
            if (freqSet.find(count) != freqSet.end()) {
                return false;  // Found duplicate frequency
            }
            freqSet.insert(count);
        }
        
        return true;  // All frequencies are unique
    }
};
