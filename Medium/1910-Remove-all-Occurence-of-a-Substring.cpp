class Solution {
public:
    // Function to remove all occurrences of a substring `part` from string `s`
    string removeOccurrences(string s, string part) {
        // Continue removing `part` as long as it is found in `s`
        while (s.length() != 0 && s.find(part) < s.length()) {
            // Find the starting index of the substring `part` in `s` and erase it
            s.erase(s.find(part), part.length());
        }
        // Return the modified string
        return s;
    }
};
