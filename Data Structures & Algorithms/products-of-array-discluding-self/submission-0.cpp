class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            result[i]=nums[i-1]*result[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            result[i]=result[i]*nums[i+1];
            nums[i]=nums[i]*nums[i+1];
        }

        return result;
    }
};
