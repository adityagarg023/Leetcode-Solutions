// countPrimes.cpp
// Solution to count the number of prime numbers less than a given number n
// Uses the Sieve of Eratosthenes algorithm for efficient prime number identification
// Time Complexity: O(n * log(log(n))), where n is the input number
// Space Complexity: O(n) for the boolean array

#include <vector>

class Solution {
public:
    // Function to count prime numbers less than n
    // @param n: Upper bound (exclusive) for counting primes
    // @return: Number of prime numbers less than n
    int countPrimes(int n) {
        // Initialize count of prime numbers
        int count = 0;
        
        // Create a boolean array to mark numbers as prime or not
        std::vector<bool> prime(n + 1, true);
        
        // Mark 0 and 1 as non-prime
        if (n > 0) prime[0] = false;
        if (n > 1) prime[1] = false;
        
        // Implement Sieve of Eratosthenes
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++; // Increment count for prime number
                
                // Mark multiples of i as non-prime
                for (long long j = (long long)i * 2; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        return count;
    }
};
