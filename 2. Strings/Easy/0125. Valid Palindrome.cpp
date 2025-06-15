// Solution to check if a string is a palindrome, ignoring non-alphanumeric characters and considering case-insensitive comparison
// Time Complexity: O(n), where n is the length of the input string
// Space Complexity: O(n) for the temporary string

#include <string>

class Solution {
public:
    // Function to check if a character is alphanumeric
    // @param ch: Character to check
    // @return: True if the character is alphanumeric, false otherwise
    bool validchar(char ch) {
        return ((ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') || 
                (ch >= '0' && ch <= '9'));
    }
    
    // Function to convert a character to lowercase
    // @param ch: Character to convert
    // @return: Lowercase version of the character if uppercase, otherwise unchanged
    char lowercase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a';
        }
        return ch;
    }
    
    // Function to check if a string is a palindrome
    // @param s: Input string (already cleaned and lowercased)
    // @return: True if the string is a palindrome, false otherwise
    bool checkpalindrome(std::string s) {
        int start = 0; // Start index
        int end = s.size() - 1; // End index
        
        // Compare characters from both ends
        while (start < end) {
            if (lowercase(s[start]) == lowercase(s[end])) {
                start++;
                end--;
            } else {
                return false; // Not a palindrome
            }
        }
        return true; // Is a palindrome
    }
    
    // Main function to check if a string is a valid palindrome
    // @param s: Input string
    // @return: True if the string is a palindrome after cleaning, false otherwise
    bool isPalindrome(std::string s) {
        // Initialize temporary string for cleaned input
        std::string temp = "";
        
        // Filter out non-alphanumeric characters
        for (int i = 0; i < s.length(); i++) {
            if (validchar(s[i])) {
                temp.push_back(s[i]);
            }
        }
        
        // Convert all characters to lowercase
        for (int i = 0; i < temp.length(); i++) {
            temp[i] = lowercase(temp[i]);
        }
        
        // Check if the cleaned string is a palindrome
        return checkpalindrome(temp);
    }
};
