class Solution {
public:
    // Function to sort an array containing only 0s, 1s, and 2s
    // This implements the Dutch National Flag algorithm
    void sortColors(vector<int>& nums) {
        int low = 0;                // Pointer for 0s
        int mid = 0;                // Pointer for current element
        int high = nums.size() - 1; // Pointer for 2s

        // Iterate until 'mid' crosses 'high'
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap the current element with the 'low' pointer and move both pointers
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                // If the element is 1, just move the 'mid' pointer
                mid++;
            } else {
                // If the element is 2, swap it with the 'high' pointer and move the 'high' pointer
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
