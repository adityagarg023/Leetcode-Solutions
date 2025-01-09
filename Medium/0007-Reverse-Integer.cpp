class Solution {
public:
    // Function to reverse the digits of an integer
    int reverse(int x) {
        int ans = 0; // Initialize the variable to store the reversed number

        // Process the number until all digits are reversed
        while (x != 0) {
            int digit = x % 10; // Extract the last digit of the number

            // Check for overflow/underflow before updating the reversed number
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if the result would exceed the 32-bit integer range
            }

            ans = (ans * 10) + digit; // Update the reversed number
            x = x / 10; // Remove the last digit from the original number
        }

        return ans; // Return the reversed number
    }
};
