// Solution to check if a given integer is a power of two
// Iteratively checks powers of 2 up to the 30th power to avoid overflow
// Time Complexity: O(1) since the loop runs a constant number of times (up to 30 iterations)
// Space Complexity: O(1) as it uses constant extra space

#include <climits>

class Solution {
public:
    // Function to check if a number is a power of two
    // @param n: Input integer to check
    // @return: True if n is a power of two, false otherwise
    bool isPowerOfTwo(int n) {
        // Handle non-positive numbers, as they are not powers of two
        if (n <= 0) {
            return false;
        }
        
        int ans = 1; // Start with 2^0 = 1
        
        // Check powers of 2 up to 2^30
        for (int i = 0; i <= 30; i++) {
            if (ans == n) {
                return true; // Found a match
            }
            // Multiply by 2 only if it won't overflow
            if (ans < INT_MAX / 2) {
                ans *= 2;
            } else {
                break; // No need to continue if ans exceeds possible range
            }
        }
        
        return false; // Not a power of two
    }
};
