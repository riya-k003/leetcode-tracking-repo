class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int max_profit =0;
        for(int i =0 ; i<n ; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            max_profit = max(max_profit , prices[i]-buy);
        }
        
        return max_profit;

        
    }
};