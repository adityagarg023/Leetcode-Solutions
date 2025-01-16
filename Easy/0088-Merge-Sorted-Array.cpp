class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize pointers for nums1 and nums2
        int i = 0, j = 0;

        // Temporary vector to store the merged result
        vector<int> ans;

        // Step 1: Merge elements from both arrays until one is exhausted
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                // Add the smaller element from nums1 or nums2
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Step 2: Add remaining elements from nums1, if any
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Step 3: Add remaining elements from nums2, if any
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        // Step 4: Copy the merged result back to nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = ans[k];
        }
    }
};
