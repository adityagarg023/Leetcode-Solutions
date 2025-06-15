// Solution to remove adjacent duplicate characters from a string
// Uses a stack-like approach with a string to track characters
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(n) for the result string

#include <string>

class Solution {
public:
    // Function to remove adjacent duplicate characters from a string
    // @param s: Input string
    // @return: String with all adjacent duplicates removed
    std::string removeDuplicates(std::string s) {
        // Initialize result string to act as a stack
        std::string ans = "";
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // If result is not empty and current character matches the last character
            if (!ans.empty() && s[i] == ans.back()) {
                ans.pop_back(); // Remove the last character (duplicate)
            } else {
                ans.push_back(s[i]); // Add current character to result
            }
        }
        
        return ans;
    }
};
