class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        int left = 0, right;
        int bestLeft = -1, bestRight = -1;
        bool isValid = false;
        vector<int> pattern(58, 0), window(58, 0);
        
        for(right = 0; right < t.size(); right++) {
            pattern[t[right]-'A']++;
            window[s[right]-'A']++;
        }
        
        while(right <= s.size()){ 
            if(left < s.size() && !pattern[s[left]-'A']){ 
                window[s[left]-'A']--;
                left++;
                continue;
            }
            
            for (int j = 0; j < 58; j++) {
                if (pattern[j] > window[j]) break;
                if (j == 57) {
                    isValid = true;
                    if(bestLeft == -1) {
                        bestLeft = left;
                        bestRight = right;
                    } else {
                        int len = bestRight - bestLeft; 
                        if(len > right - left){
                            bestLeft = left;
                            bestRight = right;
                        }
                    }
                    window[s[left]-'A']--;
                    left++;
                }
            }
            if(!isValid){    
                if (right < s.size()) {
                    window[s[right++]-'A']++;
                } else {
                    break;
                }
            }
            isValid = false;
        }
        if(bestLeft == -1) return "";
        return s.substr(bestLeft, bestRight - bestLeft);
    }
};
