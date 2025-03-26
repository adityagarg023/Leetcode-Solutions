// File: median_of_two_sorted_arrays.cpp
// Description: Solution to find median of two sorted arrays
// Time Complexity: O(m + n), where m and n are lengths of input arrays
// Space Complexity: O(m + n) for the merged array

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the median of two sorted arrays by merging them
     * @param nums1 First sorted array of integers
     * @param nums2 Second sorted array of integers
     * @return Median value as a double
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;  // Index for nums1
        int j = 0;  // Index for nums2
        
        // Merge the two sorted arrays into a single vector
        vector<int> merged;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements from nums1, if any
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements from nums2, if any
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        // Calculate median based on merged array size
        double median;
        int n = merged.size();
        
        if (n % 2 == 0) {
            // If even length, average of two middle elements
            median = static_cast<double>(merged[n/2] + merged[(n/2) - 1]) / 2.0;
        } else {
            // If odd length, middle element
            median = static_cast<double>(merged[n/2]);
        }
        
        return median;
    }
};
