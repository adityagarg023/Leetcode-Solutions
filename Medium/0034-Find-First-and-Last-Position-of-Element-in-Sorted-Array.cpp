class Solution {
public:
    // Function to find the first occurrence of the target in a sorted array
    int firstocc(vector<int>& nums, int target) {
        int s = 0;                          // Start of the search range
        int e = nums.size() - 1;            // End of the search range
        int m = s + (e - s) / 2;            // Middle index to prevent overflow
        int ans = -1;                       // Variable to store the first occurrence index

        // Binary search to find the first occurrence
        while (s <= e) {
            m = s + (e - s) / 2;            // Update the middle index
            if (nums[m] == target) {        // If target is found
                ans = m;                    // Update the answer with the current index
                e = m - 1;                  // Move to the left half to find the first occurrence
            } else if (nums[m] < target) {  // If the middle element is smaller than the target
                s = m + 1;                  // Move to the right half
            } else {                        // If the middle element is greater than the target
                e = m - 1;                  // Move to the left half
            }
        }
        return ans;                         // Return the index of the first occurrence, or -1 if not found
    }

    // Function to find the last occurrence of the target in a sorted array
    int lastocc(vector<int>& nums, int target) {
        int s = 0;                          // Start of the search range
        int e = nums.size() - 1;            // End of the search range
        int m = s + (e - s) / 2;            // Middle index to prevent overflow
        int ans = -1;                       // Variable to store the last occurrence index

        // Binary search to find the last occurrence
        while (s <= e) {
            m = s + (e - s) / 2;            // Update the middle index
            if (nums[m] == target) {        // If target is found
                ans = m;                    // Update the answer with the current index
                s = m + 1;                  // Move to the right half to find the last occurrence
            } else if (nums[m] < target) {  // If the middle element is smaller than the target
                s = m + 1;                  // Move to the right half
            } else {                        // If the middle element is greater than the target
                e = m - 1;                  // Move to the left half
            }
        }
        return ans;                         // Return the index of the last occurrence, or -1 if not found
    }

    // Function to find the starting and ending positions of a given target in a sorted array
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;                    // Vector to store the result
        ans.push_back(firstocc(nums, target)); // Find and store the first occurrence index
        ans.push_back(lastocc(nums, target));  // Find and store the last occurrence index
        return ans;                         // Return the result
    }
};
