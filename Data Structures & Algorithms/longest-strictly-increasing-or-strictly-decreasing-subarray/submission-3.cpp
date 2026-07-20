class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int inc = 1, dec = 1, max_len = 1;

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] > nums[i + 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            max_len = std::max({max_len, inc, dec});
        }

        return max_len;
    }
};