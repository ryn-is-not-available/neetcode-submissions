class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen;
        int ans = 0,left=0, right=0;
        while (right<s.size()) {
            if(!seen.contains(s[right]) || seen[s[right]]<left) {
                seen[s[right]]=right;
                right++;
            } else {
                ans=max(ans,right-left);
                left=seen[s[right]]+1;
                seen[s[right++]]=right;
            }
        }

        return max(ans,right-left);
    }
};
