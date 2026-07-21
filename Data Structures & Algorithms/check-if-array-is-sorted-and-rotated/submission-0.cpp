class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotationChance=true;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                if(rotationChance)rotationChance=false;
                else return false;
            }
        }
        return true;
    }
};