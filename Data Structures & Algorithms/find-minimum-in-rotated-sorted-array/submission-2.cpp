class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0 , n = nums.size() , right = n-1;

        while (left<right) {
            int cut = (left+right)/2;
            if (nums[cut] > nums[right]) left=cut+1;
            else right=cut;
        }
        return nums[left];
    }
};
