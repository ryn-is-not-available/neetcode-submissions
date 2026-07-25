class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        for (int num : nums) {
            count[min(num, n)]++;
        }

        int accumulator = 0;
        for (int i = n; i >= 1; i--) {
            accumulator += count[i];
            if (accumulator == i) return i;
        }

        return -1;
    }
};