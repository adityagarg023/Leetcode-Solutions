class Solution {
public:
    // Function to rotate the array `nums` by `k` steps to the right
    void rotate(vector<int>& nums, int k) {
        // Create a new array to store the rotated elements
        vector<int> ans(nums.size());

        // Adjust `k` to handle cases where k is greater than the size of the array
        k = k % nums.size();

        // Populate the new array by shifting elements to their new positions
        for (int i = 0; i < nums.size(); i++) {
            ans[(i + k) % nums.size()] = nums[i];
        }

        // Copy the rotated array back into the original array
        nums = ans;
    }
};
