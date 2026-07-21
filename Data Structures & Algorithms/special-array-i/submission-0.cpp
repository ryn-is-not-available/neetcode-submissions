class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2 == nums[i+1]%2)return false;
        }
        return true;
    }
};