// Solution to check if a number is an Armstrong number
// An Armstrong number is a number that is equal to the sum of its digits each raised to the power of the number of digits
// Time Complexity: O(log n) for counting digits and computing sum, where n is the input number
// Space Complexity: O(1) as it uses constant extra space

#include <cmath>

class Solution {
private:
    // Function to count the number of digits in an integer
    // @param n: Input integer
    // @return: Number of digits in n
    int countDigits(int n) {
        // Handle special case for 0
        if (n == 0) {
            return 1;
        }
        
        int count = 0;
        // Count digits by dividing by 10
        while (n != 0) {
            n /= 10;
            count++;
        }
        return count;
    }
    
public:
    // Function to check if a number is an Armstrong number
    // @param n: Input integer to check
    // @return: True if n is an Armstrong number, false otherwise
    bool isArmstrong(int n) {
        int original = n; // Store original number for comparison
        int count = countDigits(n); // Get number of digits
        int sum = 0; // Sum of digits raised to power of count
        
        // Calculate sum of each digit raised to power of count
        while (n > 0) {
            int digit = n % 10; // Extract last digit
            sum += std::pow(digit, count); // Add digit^count to sum
            n /= 10; // Remove last digit
        }
        
        // Check if sum equals original number
        return sum == original;
    }
};
