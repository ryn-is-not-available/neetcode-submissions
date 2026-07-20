class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int j=0,rightSum=0,leftSum=0;
        for(int i=0;i<nums.size();i++){
            rightSum+=nums[i];
        }

        for(;j<nums.size();j++){
            rightSum-=nums[j];
            if(rightSum==leftSum) return j;
            leftSum+=nums[j];
        }
        return -1;
    }
};