class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (strs.empty()) return "";
        
        for (size_t j = 0; j < strs[0].size(); j++) {
            char c = strs[0][j];
            
            for (size_t i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[i][j] != c) {
                    return strs[0].substr(0, j);
                }
            }
        }
        
        return strs[0];
    }
};