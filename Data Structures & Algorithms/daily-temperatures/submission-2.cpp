class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> monoStk;
        vector<int> ans(n,0);
        monoStk.push({temperatures[n-1],n-1});
        for (int i = n-2 ; i>=0 ; i--) {
            while(temperatures[i]>=monoStk.top().first) {
                monoStk.pop();
                if(monoStk.empty()) {
                    break;
                }
            }
            if(monoStk.empty()) ans[i]=0;
            else ans[i]=monoStk.top().second-i;

            monoStk.push({temperatures[i],i});
        }
        return ans;
    }
};
