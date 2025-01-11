class Solution {
public:
    // Function to find the single number that appears only once in the array
    int singleNumber(vector<int>& nums) {
        int ans = nums[0]; // Initialize 'ans' with the first element of the array

        // XOR all elements of the array
        // The property of XOR ensures that duplicate numbers cancel each other out
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        // Return the single number that is left after all pairs are canceled
        return ans;
    }
};
