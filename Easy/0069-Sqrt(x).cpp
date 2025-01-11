class Solution {
public:
    // Function to compute the square root of a given number 'x' (integer part only)
    int mySqrt(int x) {
        // Edge case: square root of 0 or 1 is the number itself
        if (x == 0 || x == 1)
            return x;

        int s = 1;              // Start of the search range
        int e = x;              // End of the search range
        int ans = 0;            // Variable to store the result (integer part of the square root)

        // Binary search to find the square root
        while (s <= e) {
            int m = s + ((e - s) / 2);  // Middle index to prevent overflow
            
            // Check if the middle value is the square root
            if (m == x / m) {
                ans = m;               // Exact square root found
                return ans;
            } else if (m < x / m) {
                ans = m;               // Update the answer (current value of m)
                s = m + 1;             // Move to the right half to find a closer value
            } else {
                e = m - 1;             // Move to the left half as m is too large
            }
        }
        return ans;                    // Return the floor value of the square root
    }
};
