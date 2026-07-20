class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                while (true) {
                    int val = grid[i][j];
                    int target_r = (val - 1) / n;
                    int target_c = (val - 1) % n;
                    if (grid[target_r][target_c] == val) {
                        break;
                    }
                    swap(grid[i][j], grid[target_r][target_c]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int expected = i * n + j + 1;
                if (grid[i][j] != expected) {
                    return {grid[i][j], expected};
                }
            }
        }

        return {};
    }
};