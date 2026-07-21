class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        vector<int> count_map(101, 0);
        for (int h : heights) {
            count_map[h]++;
        }

        int mismatches = 0;
        int expected_height = 1;

        for (int actual_height : heights) {
            while (count_map[expected_height] == 0) {
                expected_height++;
            }

            if (actual_height != expected_height) {
                mismatches++;
            }

            count_map[expected_height]--;
        }

        return mismatches;
    }
};