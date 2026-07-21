class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[500]={0};
        for(int i=0;i<nums.size();i++){
            freq[nums[i]-1]++;
        }
        for(int i=0;i<500;i++){
            if(freq[i]%2)return false;
        }
        return true;
    }
};