// File: trapping_rain_water.cpp
// Description: Solution to calculate trapped rainwater between buildings
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it uses only constant extra space

#include <vector>
#include <algorithm>  // for std::max
using namespace std;

class Solution {
public:
    /**
     * Calculates the amount of rainwater that can be trapped between bars
     * @param height Vector containing heights of bars
     * @return Total units of water trapped
     */
    int trap(vector<int>& height) {
        // Handle empty input case
        if (height.empty()) {
            return 0;
        }
        
        int left = 0;               // Left pointer
        int right = height.size() - 1;  // Right pointer
        int leftMax = 0;           // Maximum height encountered from left
        int rightMax = 0;          // Maximum height encountered from right
        int water = 0;             // Total trapped water
        
        // Process bars from both ends until pointers meet
        while (left < right) {
            // Update maximum heights from both sides
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            
            // Water trapped at current position is determined by
            // the smaller of the two maximum heights
            if (leftMax <= rightMax) {
                water += leftMax - height[left];
                left++;
            } else {
                water += rightMax - height[right];
                right--;
            }
        }
        
        return water;
    }
};
