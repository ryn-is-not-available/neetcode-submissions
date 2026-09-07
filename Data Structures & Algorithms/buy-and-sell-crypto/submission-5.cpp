class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        if(prices.size()==1) return 0;
        int Buy=101;
        int Sell=0;
        int ans =0;
        
        for (int i=0 ; i<prices.size() ; i++) {
            
            if (prices[i] > Sell) {
                Sell = prices[i];
                ans=max(ans,Sell-Buy);
            } 
            if(prices[i] < Buy) {
                Buy = prices[i];
                Sell=0;
                continue;
            }
        }

        return ans;
    }
};
