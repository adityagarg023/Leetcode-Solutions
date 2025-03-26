// File: power_of_two.cpp
// Description: Solution to check if a number is a power of 2 using bitwise operation
// Time Complexity: O(1) with single operation
// Space Complexity: O(1) using no extra space

using namespace std;

class Solution {
public:
    /**
     * Checks if a given number is a power of 2 using bitwise operation
     * A power of 2 has exactly one 1-bit in its binary representation
     * @param n Integer to check
     * @return True if n is a power of 2, false otherwise
     */
    bool isPowerOfTwo(int n) {
        // n > 0 checks for positive numbers
        // n & (n-1) is 0 only for powers of 2
        return n > 0 && (n & (n - 1)) == 0;
    }
};
