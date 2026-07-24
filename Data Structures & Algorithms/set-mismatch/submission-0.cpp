class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int correctIdx = nums[i] - 1;            
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                i++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return {nums[j], j + 1};
            }
        }

        return {};
    }
};