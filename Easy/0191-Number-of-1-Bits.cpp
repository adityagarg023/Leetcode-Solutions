class Solution {
public:
    // Function to calculate the number of '1' bits in the binary representation of a number
    int hammingWeight(uint32_t n) {
        int count = 0; // Initialize counter to track the number of '1' bits

        // Loop until all bits are processed
        while (n != 0) {
            if (n & 1) { // Check if the least significant bit is '1'
                count++; // Increment the count if true
            }
            n = n >> 1; // Right shift the bits of the number by 1
        }
        return count; // Return the total count of '1' bits
    }
};
