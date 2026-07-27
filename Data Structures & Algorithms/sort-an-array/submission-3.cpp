class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int minVal = -50000;
        int maxVal = 50000;
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);

        for (int x : nums) {
            count[x - minVal]++;
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                nums[index++] = i + minVal;
                count[i]--;
            }
        }

        return nums;
    }
};