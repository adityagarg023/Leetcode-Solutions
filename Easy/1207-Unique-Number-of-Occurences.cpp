class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap; // To count occurrences of each number
        unordered_set<int> freqSet;     // To check for unique frequencies

        // Count occurrences
        for (int num : arr) {
            freqMap[num]++;
        }

        // Check for unique frequencies
        for (auto& [key, value] : freqMap) {
            if (freqSet.find(value) != freqSet.end()) {
                return false; // Duplicate frequency found
            }
            freqSet.insert(value);
        }

        return true; // All frequencies are unique
    }
};
