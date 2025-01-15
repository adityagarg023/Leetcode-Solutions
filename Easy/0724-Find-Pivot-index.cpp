class Solution {
public:
    // Function to find the pivot index of an array
    // Pivot index is the index where the sum of elements to the left 
    // is equal to the sum of elements to the right
    int pivotIndex(vector<int>& nums) {
        int total = 0; // Variable to store the total sum of the array

        // Calculate the total sum of all elements in the array
        for (int i = 0; i < nums.size(); i++)
            total += nums[i];

        int sum1 = 0; // Variable to keep track of the cumulative sum from the left

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            int sum2 = total - sum1 - nums[i]; // Calculate the right-side sum

            // Check if the left-side sum equals the right-side sum
            if (sum1 == sum2)
                return i; // Pivot index found

            // Update the left-side cumulative sum
            sum1 += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};
