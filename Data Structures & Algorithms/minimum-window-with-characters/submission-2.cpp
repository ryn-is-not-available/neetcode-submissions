class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> pattern(58, 0), window(58, 0);
        int requiredMatches = 0;
        
        for (char c : t) {
            if (pattern[c - 'A'] == 0) {
                requiredMatches++;
            }
            pattern[c - 'A']++;
        }

        int left = 0, currentMatches = 0;
        int bestLeft = -1, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            int rightChar = s[right] - 'A';
            window[rightChar]++;

            // If this character's frequency now matches what t requires
            if (pattern[rightChar] > 0 && window[rightChar] == pattern[rightChar]) {
                currentMatches++;
            }


            while (currentMatches == requiredMatches) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    bestLeft = left;
                }

                int leftChar = s[left] - 'A';
                window[leftChar]--;
                
                if (pattern[leftChar] > 0 && window[leftChar] < pattern[leftChar]) {
                    currentMatches--;
                }
                left++;
            }
        }

        if (bestLeft == -1) return "";
        return s.substr(bestLeft, minLen);
    }
};
