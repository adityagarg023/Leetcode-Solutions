// Solution to remove all occurrences of a substring from a string
// Repeatedly finds and erases the substring until it is no longer found
// Time Complexity: O(n * m), where n is the length of string s and m is the length of part
// Space Complexity: O(1) as it modifies the string in-place

#include <string>

class Solution {
public:
    // Function to remove all occurrences of a substring from a string
    // @param s: Input string from which to remove occurrences
    // @param part: Substring to be removed
    // @return: String with all occurrences of part removed
    std::string removeOccurrences(std::string s, std::string part) {
        // Continue removing occurrences of part while it exists in s
        while (s.length() != 0 && s.find(part) < s.length()) {
            // Find the starting index of part and erase it
            s.erase(s.find(part), part.length());
        }
        
        return s;
    }
};
