class Solution {
public:
    // Function to check if a given number is a power of two
    bool isPowerOfTwo(int n) {
        int ans = 1; // Start with 2^0 = 1

        // Loop through powers of 2 from 2^0 to 2^30 (as 2^31 exceeds the range of int)
        for (int i = 0; i <= 30; i++) {
            // If 'ans' matches 'n', then 'n' is a power of two
            if (ans == n) {
                return true;
            }

            // Multiply 'ans' by 2 to move to the next power of 2
            // Ensure no overflow occurs before the multiplication
            if (ans < INT_MAX / 2) {
                ans = ans * 2;
            }
        }

        // If no match is found, 'n' is not a power of two
        return false;
    }
};
