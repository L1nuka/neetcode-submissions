class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n == 1)
            return 0;

        int lowBuy = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < n; i++) {
            maxProfit = max(prices[i]-lowBuy,maxProfit);
            lowBuy = min(prices[i],lowBuy);
        }

        return maxProfit;
    }
};
