// Solution to check if an integer is a palindrome
// Reverses the integer and compares it with the original
// Time Complexity: O(log x), where x is the input number (based on number of digits)
// Space Complexity: O(1) as it uses constant extra space

#include <climits>

class Solution {
public:
    // Function to reverse an integer
    // @param x: Input integer to reverse
    // @return: Reversed integer, or 0 if overflow occurs
    int reverse(int x) {
        int ans = 0; // Store reversed number
        
        while (x != 0) {
            int digit = x % 10; // Extract last digit
            // Check for overflow before multiplying
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            ans = (ans * 10) + digit; // Build reversed number
            x = x / 10; // Remove last digit
        }
        
        return ans;
    }
    
    // Function to check if an integer is a palindrome
    // @param x: Input integer to check
    // @return: True if x is a palindrome, false otherwise
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }
        
        // Compare original number with its reverse
        return reverse(x) == x;
    }
};
