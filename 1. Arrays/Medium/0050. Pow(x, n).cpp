// File: power_function.cpp
// Description: Solution to calculate x raised to power n efficiently
// Time Complexity: O(log n), where n is the exponent
// Space Complexity: O(1) using only constant extra space

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Calculates x raised to power n using fast exponentiation
     * @param x Base number
     * @param n Exponent (can be negative)
     * @return x raised to power n
     */
    double myPow(double x, int n) {
        // Handle edge cases
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        
        // Use long long to handle INT_MIN case
        long long exponent = n;
        if (exponent < 0) {
            x = 1 / x;
            exponent = -exponent;
        }
        
        double result = 1;         // Final result
        double currentProduct = x;  // Current power of x
        
        // Fast exponentiation using binary representation
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                // If current bit is 1, multiply result with current power
                result *= currentProduct;
            }
            // Square the current power
            currentProduct *= currentProduct;
            exponent /= 2;
        }
        
        return result;
    }
};
