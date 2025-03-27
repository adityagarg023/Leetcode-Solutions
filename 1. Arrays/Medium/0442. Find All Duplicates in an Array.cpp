// Description: Solution to find all duplicate numbers in an array
// Time Complexity: O(n log n) due to sorting, where n is the array length
// Space Complexity: O(n) for the output vector in worst case

#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    /**
     * Finds all duplicate numbers in an array
     * @param nums Vector of integers where each number is in range [1, n]
     * @return Vector containing all numbers that appear twice
     */
    vector<int> findDuplicates(vector<int>& nums) {
        // Sort the array to bring duplicates together
        sort(nums.begin(), nums.end());
        vector<int> duplicates;
        
        // Compare adjacent elements to find duplicates
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                duplicates.push_back(nums[i]);
            }
        }
        
        return duplicates;
    }
};
