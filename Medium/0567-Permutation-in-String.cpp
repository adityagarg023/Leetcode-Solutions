class Solution {
public:
    // Function to check if two frequency arrays are equal
    bool checkequal(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    // Function to determine if `s1`'s permutation is a substring of `s2`
    bool checkInclusion(string s1, string s2) {
        // Frequency array for characters in `s1`
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // Sliding window frequency array for `s2`
        int count2[26] = {0};
        int i = 0, winsize = s1.length();

        // Initialize the first window
        while (i < winsize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Check if the first window matches
        if (checkequal(count1, count2))
            return true;

        // Slide the window across `s2`
        while (i < s2.length()) {
            // Add the new character to the window
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;

            // Remove the old character from the window
            char oldchar = s2[i - winsize];
            index = oldchar - 'a';
            count2[index]--;

            // Move to the next position
            i++;

            // Check if the current window matches
            if (checkequal(count1, count2))
                return true;
        }

        // If no matching window is found
        return false;
    }
};
