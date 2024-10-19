class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int buy = prices[0];
        for (auto i : prices) {
            if (i < buy)
                buy = i;
            else {
                total += i - buy;
                buy = i;
            }
        }
        return total;
    }
};