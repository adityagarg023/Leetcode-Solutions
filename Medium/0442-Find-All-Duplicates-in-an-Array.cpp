class Solution {
public:
    // Function to find all duplicates in the input array
    // Returns a vector containing elements that appear twice in the array
    vector<int> findDuplicates(vector<int>& nums) {
        // Sort the input array to bring duplicates next to each other
        sort(nums.begin(), nums.end());

        vector<int> ans; // To store the duplicate elements

        // Iterate through the sorted array, starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is equal to the previous element, it's a duplicate
            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]); // Add the duplicate to the result
            }
        }

        return ans; // Return the list of duplicates
    }
};
