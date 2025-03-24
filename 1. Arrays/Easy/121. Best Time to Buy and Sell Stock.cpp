// Description: Solution to find maximum profit from single stock transaction
// Time Complexity: O(n), where n is the length of the prices array
// Space Complexity: O(1) using only constant extra space

#include <vector>
#include <algorithm>  // for std::max and std::min
using namespace std;

class Solution {
public:
    /**
     * Finds maximum profit possible from one buy and one sell transaction
     * @param prices Vector of daily stock prices
     * @return Maximum achievable profit (0 if no profit possible)
     */
    int maxProfit(vector<int>& prices) {
        // Handle empty input
        if (prices.empty()) {
            return 0;
        }
        
        int minPrice = prices[0];  // Minimum price seen so far
        int maxProfit = 0;         // Maximum profit achievable
        int n = prices.size();     // Array size
        
        // Iterate through prices once
        for (int i = 0; i < n; i++) {
            // Calculate potential profit if sold at current price
            int currentProfit = prices[i] - minPrice;
            // Update maximum profit if current profit is higher
            maxProfit = max(maxProfit, currentProfit);
            // Update minimum price if current price is lower
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};
