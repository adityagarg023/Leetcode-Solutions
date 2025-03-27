// File: peak_index_mountain_array.cpp
// Description: Solution to find peak index in a mountain array
// Time Complexity: O(log n), where n is the length of the input array
// Space Complexity: O(1) as it uses only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the index of the peak element in a mountain array
     * A mountain array increases to a peak then decreases
     * @param arr Vector of integers forming a mountain array
     * @return Index of the peak element
     */
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;              // Start of search range
        int end = arr.size();       // End of search range
        
        // Binary search to find the peak
        while (start < end) {
            int mid = start + (end - start) / 2;  // Avoid integer overflow
            
            if (arr[mid] < arr[mid + 1]) {
                // Peak is in right half (ascending part)
                start = mid + 1;
            } else {
                // Peak is in left half or at mid (descending part)
                end = mid;
            }
        }
        
        return start;  // Start and end converge at peak index
    }
};
