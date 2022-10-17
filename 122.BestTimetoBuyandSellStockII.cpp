class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i=1;i<prices.size();i++) {
            result = max(result, result + (prices[i] - prices[i - 1]));
        }
        return result;
    }
};