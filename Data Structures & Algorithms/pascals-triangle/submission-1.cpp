class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> res;
        res.reserve(numRows);

        for (int i = 0; i < numRows; i++) {
            res.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        
        return res;
    }
};