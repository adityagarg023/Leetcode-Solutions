class Solution {
public:
    // Function to calculate the bitwise complement of an integer
    int bitwiseComplement(int n) {
        int m = n;      // Copy of the input number
        int mask = 0;   // Mask to isolate the bits of `n`

        // Special case: If the input is 0, the complement is 1
        if (n == 0) {
            return 1;
        }

        // Create a mask with all bits set to 1 for the length of `n`
        while (m != 0) {
            mask = (mask << 1) | 1; // Shift left and add a 1
            m = m >> 1;             // Right shift to process the next bit
        }

        // Calculate the bitwise complement using the mask
        int ans = (~n) & mask; // Flip the bits of `n` and isolate the relevant bits
        return ans;
    }
};
