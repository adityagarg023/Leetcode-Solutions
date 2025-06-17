// Solution to check if a permutation of string s1 is a substring of string s2
// Uses a sliding window approach with frequency arrays to compare character counts
// Time Complexity: O(n + m), where n is the length of s1 and m is the length of s2
// Space Complexity: O(1) as the frequency arrays are fixed size (26 for lowercase letters)

#include <string>

class Solution {
public:
    // Function to compare two frequency arrays for equality
    // @param a: First frequency array
    // @param b: Second frequency array
    // @return: True if arrays are equal, false otherwise
    bool checkequal(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    
    // Function to check if a permutation of s1 is a substring of s2
    // @param s1: First string (to find permutation of)
    // @param s2: Second string (to search in)
    // @return: True if a permutation of s1 is found in s2, false otherwise
    bool checkInclusion(std::string s1, std::string s2) {
        // Initialize frequency array for s1
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a'; // Map character to index (0-25)
            count1[index]++;
        }
        
        // Initialize frequency array for sliding window in s2
        int count2[26] = {0};
        int i = 0;
        int winsize = s1.length(); // Window size equals length of s1
        
        // Process first window of size s1.length()
        while (i < winsize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        // Check if the first window matches
        if (checkequal(count1, count2)) {
            return true;
        }
        
        // Slide the window and check subsequent windows
        while (i < s2.length()) {
            // Add new character to window
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;
            
            // Remove character from start of previous window
            char oldchar = s2[i - winsize];
            index = oldchar - 'a';
            count2[index]--;
            
            i++;
            
            // Check if current window matches
            if (checkequal(count1, count2)) {
                return true;
            }
        }
        
        return false; // No matching permutation found
    }
};
