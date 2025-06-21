// Solution to compute x raised to the power n (x^n) using binary exponentiation
// Handles both positive and negative exponents efficiently
// Time Complexity: O(log n), where n is the exponent
// Space Complexity: O(1) as it uses constant extra space

#include <climits>

class Solution {
public:
    // Function to compute x raised to the power n
    // @param x: Base number (double)
    // @param n: Exponent (integer)
    // @return: Result of x^n
    double myPow(double x, int n) {
        // Handle edge cases
        if (x == 0) {
            return 0; // 0 raised to any power is 0
        }
        if (n == 0) {
            return 1; // Any number raised to power 0 is 1
        }
        
        // Use long long to handle INT_MIN overflow
        long long N = n;
        
        // Handle negative exponents
        if (N < 0) {
            x = 1 / x; // Invert base for negative exponent
            N = -N; // Make exponent positive
        }
        
        double ans = 1; // Initialize result
        double currPro = x; // Current product starts with base
        
        // Binary exponentiation
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= currPro; // Multiply result by current product if exponent is odd
            }
            currPro *= currPro; // Square the current product
            N /= 2; // Divide exponent by 2
        }
        
        return ans;
    }
};
