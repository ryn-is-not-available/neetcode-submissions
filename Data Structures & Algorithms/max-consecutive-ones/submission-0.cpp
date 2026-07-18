class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best=0,current=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) current++;
            else{
                best=max(best,current);
                current=0;
            }
        }
        best=max(best,current);
        return best;
    }
};