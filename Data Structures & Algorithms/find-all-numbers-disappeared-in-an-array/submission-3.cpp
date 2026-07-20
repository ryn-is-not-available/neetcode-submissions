class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> exist(nums.size(),0);
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            exist[nums[i]-1]=1;
        }
        for(int i=1;i<=nums.size();i++){
            if(!exist[i-1])res.push_back(i);
        }
        return res;
    }
};