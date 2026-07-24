class Solution {
public:
    int longestPalindrome(string s) {
        int carac[128] = {0};
        int len = 0;
        bool hasOdd = false;

        for (char ch : s) {
            carac[(unsigned char)ch]++;
        }

        for (int count : carac) {
            len += (count / 2) * 2;
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        return hasOdd ? len + 1 : len;
    }
};