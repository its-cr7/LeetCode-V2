class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int count = 0;
            int sum = 0;
            
            // Find divisors up to sqrt(num)
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    count++;
                    sum += i;
                    
                    // Add the corresponding divisor if different
                    if (i != num / i) {
                        count++;
                        sum += num / i;
                    }
                    
                    // Early exit if more than 4 divisors
                    if (count > 4) break;
                }
            }
            
            // Add to total if exactly 4 divisors
            if (count == 4) {
                totalSum += sum;
            }
        }
        
        return totalSum;
    }
};