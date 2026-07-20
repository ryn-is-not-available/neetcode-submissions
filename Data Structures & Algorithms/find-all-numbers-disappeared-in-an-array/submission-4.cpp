class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int x;
        for(int i=0;i<nums.size();i++){
            x=abs(nums[i]);
            if(nums[x-1]>0) nums[x-1]=-nums[x-1];
        }
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]>0)res.push_back(i);
        }
        return res;
    }
};