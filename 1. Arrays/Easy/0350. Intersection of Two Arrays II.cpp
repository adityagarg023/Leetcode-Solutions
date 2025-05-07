// File: array_intersect.cpp
// Description: Solution to find intersection of two arrays using hash map
// Time Complexity: O(n + m), where n and m are array lengths
// Space Complexity: O(min(n, m)) for hash map and output

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * Finds intersection of two arrays including duplicates
     * Each element appears as many times as it shows in both arrays
     * @param nums1 First vector of integers
     * @param nums2 Second vector of integers
     * @return Vector containing intersection elements
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;  // Store counts of nums1 elements
        vector<int> result;                // Store intersection
        
        // Count elements in nums1
        for (int num : nums1) {
            countMap[num]++;
        }
        
        // Check nums2 elements against countMap
        for (int num : nums2) {
            if (countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;
            }
        }
        
        return result;
    }
};
