class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        int left=0,maxFreq=0,best=0;
        vector<int> count(26,0);

        for (int right = 0 ; right<s.size() ; right++ ) {
            int currentLength = right-left+1;

            maxFreq=max(maxFreq,++count[s[right]-'A']);
            if (currentLength-maxFreq > k && left <right) {
                count[s[left++]-'A']--;
                currentLength--;
            };
            best=max(best,right-left+1);
        }
        return best;
    }
};
