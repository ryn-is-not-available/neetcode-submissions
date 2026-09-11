class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int contextWindow[26] = {0};
        if(s2.size()<s1.size()) return false;
        for (int i=0 ; i < s1.size() ; i++) {
            freq1[s1[i]-'a']++;
            contextWindow[s2[i]-'a']++;
        }
        int m = s1.size();
        int left = 0;
        for(int right = m; right <= s2.size() ; right++ ) {
            for (int i=0 ; i < 26 ; i++) {
                if(freq1[i]!=contextWindow[i]) break;
                if(i == 25) return true;
            }
            if(right<s2.size()) {
                contextWindow[s2[left++]-'a']--;
                contextWindow[s2[right]-'a']++;
            }
        }
        return false;
    }
};
