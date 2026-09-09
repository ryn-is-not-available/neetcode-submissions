class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxFreq=0,best=0;
        unordered_map<char,int> count;

        for (int right = 0 ; right<s.size() ; right++ ) {
            int currentLength = right-left+1;
            count[s[right]]++;
            maxFreq=max(maxFreq,count[s[right]]);
            while (currentLength-maxFreq > k && left <right) {
                count[s[left++]]--;
                currentLength--;
            };
            best=max(best,right-left+1);
        }
        return best;
    }
};
