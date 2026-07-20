class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum=nums[0],bestSum=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currentSum+=nums[i];
            }else{
                bestSum=max(bestSum,currentSum);
                currentSum=nums[i];
            }
            bestSum=max(bestSum,currentSum);
        }
        return bestSum;
    }
};