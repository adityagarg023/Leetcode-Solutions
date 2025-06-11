// Solution to compute XOR of subarrays for given queries
// Uses prefix XOR array to efficiently calculate XOR of any subarray
// Time Complexity: O(n + q), where n is the size of the input array and q is the number of queries
// Space Complexity: O(n) for the prefix array and O(q) for the result

#include <vector>

class Solution {
public:
    // Function to compute XOR of subarrays for given queries
    // @param arr: Input array of integers
    // @param queries: Vector of queries where each query is [L, R] for subarray bounds
    // @return: Vector containing XOR results for each query
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        int n = arr.size(); // Size of the input array
        
        // Initialize prefix XOR array
        std::vector<int> prefix(n);
        prefix[0] = arr[0]; // First element
        
        // Compute prefix XOR array
        // prefix[i] stores XOR of all elements from arr[0] to arr[i]
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        
        // Initialize result vector for query answers
        std::vector<int> result;
        
        // Process each query
        for (const auto& q : queries) {
            int L = q[0]; // Left bound of subarray
            int R = q[1]; // Right bound of subarray
            
            // If L is 0, XOR is prefix[R]
            // Otherwise, XOR is prefix[R] ^ prefix[L-1]
            if (L == 0) {
                result.push_back(prefix[R]);
            } else {
                result.push_back(prefix[R] ^ prefix[L - 1]);
            }
        }
        
        return result;
    }
};
