class Solution {
public:
    int specialArray(vector<int>& nums) {
        int value[1001]={0};
        for(int i=0;i<nums.size();i++){
            value[nums[i]]++;
        }
        int accumlator=0;
        for(int i=1000;i>=0;i--){
            accumlator+=value[i];
            if(accumlator == i) return i;
        }
        return -1;
    }
};