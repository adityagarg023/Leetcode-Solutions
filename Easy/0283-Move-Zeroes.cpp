class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Pointer to track the position for the next non-zero element
        int zero = 0;

        // Traverse the array to find non-zero elements
        for (int nonzero = 0; nonzero < nums.size(); nonzero++) {
            if (nums[nonzero] != 0) {
                // Swap the current non-zero element with the element at the 'zero' pointer
                swap(nums[zero], nums[nonzero]);
                // Increment the zero pointer to prepare for the next non-zero element
                zero++;
            }
        }
    }
};
