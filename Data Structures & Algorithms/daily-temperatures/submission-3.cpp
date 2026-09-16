class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n = tmp.size();
        stack<int> monoStk;
        vector<int> ans(n,0);
        monoStk.push(n-1);
        for (int i = n-2 ; i>=0 ; i--) {
            while(tmp[i]>=tmp[monoStk.top()]) {
                monoStk.pop();
                if(monoStk.empty()) {
                    break;
                }
            }
            if(monoStk.empty()) ans[i]=0;
            else ans[i]=monoStk.top()-i;

            monoStk.push(i);
        }
        return ans;
    }
};
