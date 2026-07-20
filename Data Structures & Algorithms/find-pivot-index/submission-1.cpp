class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int rightSum =accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            rightSum -= nums[i];
            if (leftSum == rightSum)return i;
            leftSum += nums[i];
        }

        return -1;
    }
};