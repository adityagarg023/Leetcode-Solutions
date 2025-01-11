class Solution {
public:
    // Function to find the pivot index in a rotated sorted array
    int pivot(vector<int>& nums) {
        int s = 0;                          // Start of the search range
        int e = nums.size() - 1;            // End of the search range
        int m = s + (e - s) / 2;            // Middle index to prevent overflow

        // Binary search to find the pivot
        while (s < e) {
            m = s + (e - s) / 2;            // Update the middle index
            if (nums[m] >= nums[0]) {       // If middle element is greater or equal to the first element
                s = m + 1;                  // Pivot lies in the right half
            } else {
                e = m;                      // Pivot lies in the left half
            }
        }
        return s;                           // 's' now points to the pivot index
    }

    // Binary search function to find the target in a specific range
    int binary(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int m = s + (e - s) / 2;        // Middle index
            if (nums[m] == target) {        // If target is found, return its index
                return m;
            } else if (nums[m] < target) {  // If middle element is smaller than target
                s = m + 1;                  // Move to the right half
            } else {                        // If middle element is greater than target
                e = m - 1;                  // Move to the left half
            }
        }
        return -1;                          // Target not found
    }

    // Function to search for a target in a rotated sorted array
    int search(vector<int>& nums, int target) {
        // Check if the array is empty
        if (nums.empty())
            return -1;

        // Find the pivot index
        int p = pivot(nums);

        // Determine which half of the rotated array the target lies in
        if (nums[p] <= target && target <= nums[nums.size() - 1]) {
            // If target lies in the right half (after the pivot)
            return binary(nums, p, nums.size() - 1, target);
        } else {
            // If target lies in the left half (before the pivot)
            return binary(nums, 0, p - 1, target);
        }
    }
};
