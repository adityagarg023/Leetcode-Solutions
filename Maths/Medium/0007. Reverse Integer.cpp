// Solution to reverse the digits of a 32-bit signed integer
// Handles overflow cases by checking before multiplying
// Time Complexity: O(log |x|), where x is the input number (based on number of digits)
// Space Complexity: O(1) as it uses constant extra space

#include <climits>

class Solution {
public:
    // Function to reverse the digits of a 32-bit signed integer
    // @param x: Input integer to reverse
    // @return: Reversed integer, or 0 if overflow occurs
    int reverse(int x) {
        int ans = 0; // Store reversed number
        
        // Process each digit
        while (x != 0) {
            int digit = x % 10; // Extract last digit
            
            // Check for overflow before multiplying
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0; // Return 0 if overflow would occur
            }
            
            ans = (ans * 10) + digit; // Build reversed number
            x /= 10; // Remove last digit
        }
        
        return ans; // Return reversed number
    }
};
