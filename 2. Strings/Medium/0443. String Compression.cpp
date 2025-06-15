// Solution to compress a character array in-place using run-length encoding
// Replaces consecutive repeating characters with the character followed by the count
// Time Complexity: O(n), where n is the length of the input array
// Space Complexity: O(1) excluding the space for output, as it modifies the array in-place

#include <vector>
#include <string>

class Solution {
public:
    // Function to compress a character array using run-length encoding
    // @param chars: Input vector of characters to be compressed
    // @return: Length of the compressed array
    int compress(std::vector<char>& chars) {
        int index = 0; // Index for writing compressed characters
        int i = 0; // Index for reading through the array
        
        // Iterate through the array
        while (i < chars.size()) {
            char currentChar = chars[i]; // Current character to process
            int count = 0; // Count of consecutive occurrences
            
            // Count consecutive occurrences of currentChar
            while (i < chars.size() && chars[i] == currentChar) {
                count++;
                i++;
            }
            
            // Write the character to the result
            chars[index++] = currentChar;
            
            // If count > 1, append the count as characters
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char c : countStr) {
                    chars[index++] = c;
                }
            }
        }
        
        return index; // Return the length of the compressed array
    }
};
