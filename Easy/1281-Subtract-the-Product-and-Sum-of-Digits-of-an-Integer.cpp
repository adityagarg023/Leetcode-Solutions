class Solution {
public:
    int subtractProductAndSum(int n) {
        // Initialize sum and product
        int sum = 0;
        int product = 1;

        // Loop through each digit of the number
        while (n != 0) {
            int digit = n % 10; // Extract the last digit
            sum += digit;      // Add the digit to the sum
            product *= digit;  // Multiply the digit to the product
            n /= 10;           // Remove the last digit from the number
        }

        // Calculate the result as the difference between product and sum
        int ans = product - sum;
        return ans;
    }
};
