class Solution {
public:
    // Function to check if the array is sorted and rotated
    bool check(vector<int>& nums) {
        int count = 0; // Count the number of "breakpoints" in the array
        
        // Loop through the array to check if the current element is greater than the next one
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
            }
        }
        
        // Check the boundary condition: last element compared to the first
        if (nums[nums.size() - 1] > nums[0]) {
            count++;
        }
        
        // The array is sorted and rotated if there is at most one "breakpoint"
        return count <= 1;
    }
};
