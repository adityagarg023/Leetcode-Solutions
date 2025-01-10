class Solution {
public:
    // Function to find all unique triplets in the array that sum up to zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input array to facilitate the two-pointer technique
        sort(nums.begin(), nums.end());

        // Vector to store the resulting triplets
        vector<vector<int>> ans;

        // Iterate through the array to fix the first element of the triplet
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Initialize two pointers: one just after the current element, and the other at the end
            int j = i + 1, k = nums.size() - 1;

            // Use the two-pointer technique to find the other two elements of the triplet
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet

                if (sum == 0) {
                    // If the sum is zero, add the triplet to the result
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for the second and third numbers
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (sum < 0) {
                    // If the sum is less than zero, move the left pointer to the right
                    j++;
                } else {
                    // If the sum is greater than zero, move the right pointer to the left
                    k--;
                }
            }
        }

        // Return the list of all unique triplets
        return ans;
    }
};
