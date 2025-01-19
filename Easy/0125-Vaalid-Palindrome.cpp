class Solution {
public:
    // Function to check if a character is alphanumeric
    bool validchar(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9'));
    }

    // Function to convert a character to lowercase
    char lowercase(char ch) {
        if ('A' <= ch && ch <= 'Z') {
            return ch - 'A' + 'a'; // Convert uppercase to lowercase
        }
        return ch; // Return as-is if already lowercase
    }

    // Function to check if a given string is a palindrome
    bool checkpalindrome(string s) {
        int start = 0, end = s.size() - 1;

        // Compare characters from start and end of the string
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

    // Main function to check if the input string is a palindrome
    bool isPalindrome(string s) {
        string temp = "";

        // Filter out non-alphanumeric characters
        for (int i = 0; i < s.length(); i++) {
            if (validchar(s[i])) {
                temp.push_back(s[i]);
            }
        }

        // Convert all characters in the filtered string to lowercase
        for (int i = 0; i < temp.length(); i++) {
            temp[i] = lowercase(temp[i]);
        }

        // Check if the cleaned string is a palindrome
        return checkpalindrome(temp);
    }
};
