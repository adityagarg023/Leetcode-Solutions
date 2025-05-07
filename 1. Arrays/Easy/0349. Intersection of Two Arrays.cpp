// File: array_intersection.cpp
// Description: Solution to find unique common elements using hash set
// Time Complexity: O(n + m), where n and m are array lengths
// Space Complexity: O(min(n, m)) for hash set and output

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * Finds unique elements common to both arrays
     * @param nums1 First vector of integers
     * @param nums2 Second vector of integers
     * @return Vector containing unique intersection elements
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());  // Store nums1 elements
        vector<int> result;                                   // Store intersection
        
        // Check nums2 elements against set1
        for (int num : nums2) {
            if (set1.count(num)) {
                result.push_back(num);
                set1.erase(num);  // Ensure uniqueness
            }
        }
        
        return result;
    }
};
