// Solution to reverse the order of words in a character array
// First reverses the entire array, then reverses each word individually
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) as it modifies the array in-place

#include <vector>
#include <algorithm>

class Solution {
public:
    // Function to reverse the order of words in a character array
    // @param s: Input vector of characters representing a string with words
    void reverseWords(std::vector<char>& s) {
        // Step 1: Reverse the entire array
        std::reverse(s.begin(), s.end());
        
        int start = 0; // Start index of current word
        
        // Step 2: Reverse each word individually
        for (int end = 0; end <= s.size(); ++end) {
            // When we reach a space or end of array, reverse the word
            if (end == s.size() || s[end] == ' ') {
                std::reverse(s.begin() + start, s.begin() + end);
                start = end + 1; // Move start to beginning of next word
            }
        }
    }
};
