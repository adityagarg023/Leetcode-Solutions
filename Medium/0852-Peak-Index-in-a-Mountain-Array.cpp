class Solution {
public:
    // Function to find the peak index in a mountain array
    // A mountain array is an array where elements increase to a peak and then decrease
    int peakIndexInMountainArray(vector<int>& arr) {
        // Binary search approach
        int s = 0; // Start of the search range
        int e = arr.size(); // End of the search range

        // Perform binary search to locate the peak index
        while (s < e) {
            int m = s + (e - s) / 2; // Calculate the middle index to avoid overflow

            // Check if the current element is in the increasing part of the mountain
            if (arr[m] < arr[m + 1]) {
                s = m + 1; // Move the start pointer to the right
            } 
            // Else, the current element is in the decreasing part of the mountain
            else {
                e = m; // Move the end pointer to the middle
            }
        }

        // The start pointer will point to the peak index
        return s;
    }
};
