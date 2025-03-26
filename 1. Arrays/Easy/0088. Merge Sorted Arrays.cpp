// File: merge_sorted_arrays.cpp
// Description: Solution to merge two sorted arrays into nums1 in-place
// Time Complexity: O(m + n), where m and n are lengths of input arrays
// Space Complexity: O(m + n) due to temporary vector

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Merges two sorted arrays into nums1
     * @param nums1 First sorted array with enough space (size m + n)
     * @param m Number of elements in nums1
     * @param nums2 Second sorted array
     * @param n Number of elements in nums2
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;  // Pointer for nums1
        int j = 0;  // Pointer for nums2
        
        // Temporary vector to store merged result
        vector<int> temp;
        
        // Merge elements from both arrays until one is exhausted
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements from nums1, if any
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements from nums2, if any
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        
        // Copy merged result back to nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = temp[k];
        }
    }
};
