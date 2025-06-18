// Solution to compute the difference between the product and sum of digits of an integer
// Iterates through each digit to calculate sum and product
// Time Complexity: O(log n), where n is the input number (based on number of digits)
// Space Complexity: O(1) as it uses constant extra space

#include <climits>

class Solution {
public:
    // Function to compute the difference between product and sum of digits
    // @param n: Input integer
    // @return: Difference between product and sum of digits
    int subtractProductAndSum(int n) {
        int sum = 0; // Sum of digits
        int product = 1; // Product of digits
        
        // Extract each digit and update sum and product
        while (n != 0) {
            int digit = n % 10; // Get last digit
            sum += digit; // Add digit to sum
            product *= digit; // Multiply digit to product
            n /= 10; // Remove last digit
        }
        
        // Calculate and return the difference
        int ans = product - sum;
        return ans;
    }
};
