class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int s_ptr = 0, t_ptr = 0;
        int m = s.size(), n = t.size();
        while (s_ptr < m && t_ptr < n) {
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++;
            }
            t_ptr++;
        }
        return s_ptr == m;
    }
};