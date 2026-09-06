class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> Setans;

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<nums.size();i++) {
            int left = i-1;
            int right = i+1;
            while (left>=0 && right <nums.size()) {
                int sum = nums[left]+nums[right]+nums[i];
                if (sum==0) {
                    Setans.insert({nums[left--],nums[right++],nums[i]});
                }else if (sum < 0) right++;
                else left--;
            }
        }
        ans.assign(Setans.begin(),Setans.end());
        return ans;
    }
};
