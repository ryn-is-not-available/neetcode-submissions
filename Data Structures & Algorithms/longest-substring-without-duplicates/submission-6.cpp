class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int seen[128];
        int left = 0;
        int best = 0;
        fill(seen,seen+128,-1);
        
        for(int right = 0; right < s.size(); right++) {
            int char_index = s[right];

            if(seen[char_index] >= left) left = seen[char_index]+1;

            seen[char_index]=right;

            best = max(best,right-left+1);
        }
        return best;
        
    }
};