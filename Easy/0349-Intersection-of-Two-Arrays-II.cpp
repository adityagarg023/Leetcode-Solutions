class Solution {
public:
    // Function to find the intersection of two arrays
    // Returns a vector containing elements common to both arrays (including duplicates)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Sort both arrays to enable the two-pointer approach
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans; // To store the intersection result
        int i = 0, j = 0; // Two pointers for traversing the arrays

        // Iterate through both arrays
        while (i < nums1.size() && j < nums2.size()) {
            // If elements are equal, add to the result and move both pointers
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } 
            // If nums1[i] is smaller, increment the first pointer
            else if (nums1[i] < nums2[j]) {
                i++;
            } 
            // If nums2[j] is smaller, increment the second pointer
            else {
                j++;
            }
        }
        return ans; // Return the intersection result
    }
};
