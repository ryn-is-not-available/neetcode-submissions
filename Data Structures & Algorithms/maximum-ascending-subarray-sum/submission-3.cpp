class Solution {
public:
    int maxAscendingSum(std::vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        if (nums.empty()) return 0;

        int currentSum = nums[0];
        int bestSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }
            bestSum = max(bestSum, currentSum);
        }

        return bestSum;
    }
};