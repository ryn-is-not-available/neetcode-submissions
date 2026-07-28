class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3]={0};
        for(int i=0;i<nums.size();i++){
            colors[nums[i]]++;
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(!colors[j]) j++;
            nums[i]=j;
            colors[j]--;
        }
    }
};