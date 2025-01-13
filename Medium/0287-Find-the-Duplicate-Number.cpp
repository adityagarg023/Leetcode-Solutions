class Solution {
public:
    // Function to find the duplicate number in an array
    // The input array contains n + 1 integers where each integer is in the range [1, n]
    int findDuplicate(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int ans; // Variable to store the duplicate number

        // Step 2: Traverse the sorted array to find the duplicate
        for (int i = 1; i < nums.size(); ++i) {
            // If two consecutive elements are equal, it means we found the duplicate
            if (nums[i] == nums[i - 1]) {
                ans = nums[i];
                break; // Exit the loop as the duplicate is found
            }
        }

        return ans; // Return the duplicate number
    }
};
