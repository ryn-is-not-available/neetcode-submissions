class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        int complement;
        for(int i=0;i<nums.size();i++){
            complement = target - nums[i];
            if(seen.contains(complement)) return {seen[complement],i};
            seen[nums[i]]=i;
        }
        return {};
    }
};
