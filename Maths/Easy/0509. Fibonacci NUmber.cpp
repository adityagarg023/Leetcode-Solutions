// Solution to compute the nth Fibonacci number using recursion
// The Fibonacci sequence is defined as: F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1
// Time Complexity: O(2^n) due to exponential recursive calls
// Space Complexity: O(n) for the recursion stack

#include <climits>

class Solution {
public:
    // Function to calculate the nth Fibonacci number
    // @param n: Non-negative integer representing the position in the Fibonacci sequence
    // @return: The nth Fibonacci number
    int fib(int n) {
        // Base case: F(0) = 0
        if (n == 0) {
            return 0;
        }
        // Base case: F(1) = 1
        if (n == 1) {
            return 1;
        }
        
        // Recursive case: F(n) = F(n-1) + F(n-2)
        int ans = fib(n - 1) + fib(n - 2);
        
        return ans;
    }
};
