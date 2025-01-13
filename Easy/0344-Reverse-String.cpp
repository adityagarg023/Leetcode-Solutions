class Solution {
public:
    // Function to reverse the characters in a vector in place
    void reverseString(vector<char>& s) {
        int start = 0;                  // Start pointer at the beginning of the vector
        int end = s.size() - 1;         // End pointer at the last element of the vector

        // Swap elements until the pointers meet or cross
        while (start <= end) {
            swap(s[start], s[end]);     // Swap the characters at the start and end pointers
            start++;                    // Move the start pointer forward
            end--;                      // Move the end pointer backward
        }
    }
};
