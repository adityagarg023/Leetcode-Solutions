class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // Calculate the total sum of the array
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        // Initialize the left sum as 0
        int leftSum = 0;

        // Iterate through the array to find the middle index
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the right sum as total - leftSum - nums[i]
            int rightSum = total - leftSum - nums[i];

            // Check if left sum equals right sum
            if (leftSum == rightSum) {
                return i; // Return the middle index
            }

            // Update the left sum by adding the current element
            leftSum += nums[i];
        }

        // If no middle index is found, return -1
        return -1;
    }
};
