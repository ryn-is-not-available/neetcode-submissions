class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n =nums.size(),j=n;
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[j]=nums[j-n];
            j++;
        }
        return ans;
    }
};