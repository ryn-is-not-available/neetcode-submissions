class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0 ,n=nums.size(), right= n-1;

        while(left<=right) {
            int cut= (left+right)/2;
            if(nums[cut]==target) return cut;
            if(nums[cut] < nums[right]) {
                if (target > nums[cut] && target <= nums[right]) left = cut+1;
                else right = cut-1;
            }else{
                if (target < nums[cut] && target >= nums[left]) right = cut-1;
                else left = cut+1;
            }
        }
        return -1;
    }
};
