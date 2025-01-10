class Solution {
public:
    // Function to find two indices such that the numbers at those indices add up to the target
    vector<int> twoSum(vector<int>& nums, int target) {
        // Vector to store the number and its corresponding index as a pair
        vector<pair<int, int>> numspair;

        // Storing each number along with its index in the pair vector
        for (int i = 0; i < nums.size(); i++) {
            numspair.push_back({nums[i], i});
        }

        // Sorting the vector based on the numbers (first element of each pair)
        sort(numspair.begin(), numspair.end());

        // Using two-pointer technique to find the two numbers that add up to the target
        int i = 0, j = numspair.size() - 1; // Start pointers at the beginning and end
        vector<int> ans; // Vector to store the result indices

        while (i < j) {
            int sum = numspair[i].first + numspair[j].first; // Calculate the sum of the two numbers

            if (sum == target) {
                // If the sum matches the target, store the original indices
                ans.push_back(numspair[i].second);
                ans.push_back(numspair[j].second);
                return ans; // Return the result
            } else if (sum < target) {
                // If the sum is less than the target, move the left pointer to the right
                i++;
            } else {
                // If the sum is greater than the target, move the right pointer to the left
                j--;
            }
        }

        // Return an empty vector if no solution is found (should not happen as per problem constraints)
        return ans;
    }
};
