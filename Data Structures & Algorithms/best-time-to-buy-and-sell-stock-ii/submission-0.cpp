class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ;
        for(int i = prices.size()-2 ; i >= 0 ; i--) {
            ans += max(0,prices[i+1]-prices[i]);
        }
        return ans;
    }
};