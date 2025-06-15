// Solution to reverse a string represented as a vector of characters Uses a two-pointer approach to swap characters from both ends
// Time Complexity: O(n/2) = O(n), where n is the length of the input vector
// Space Complexity: O(1) as it modifies the input in-place

#include <vector>

class Solution {
public:
    // Function to reverse a string represented as a vector of characters
    // @param s: Input vector of characters to be reversed
    void reverseString(std::vector<char>& s) {
        int start = 0; // Start index
        int end = s.size() - 1; // End index
        
        // Swap characters from both ends until pointers meet
        while (start <= end) {
            std::swap(s[start], s[end]); // Swap characters
            start++; // Move start pointer right
            end--; // Move end pointer left
        }
    }
};
