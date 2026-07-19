class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int charToPositionS[256] = {0};
        int charToPositionT[256] = {0};
      
        int length = s.size();
      

        for (int i = 0; i < length; ++i) {
            char charFromS = s[i];
            char charFromT = t[i];
          

            if (charToPositionS[charFromS] != charToPositionT[charFromT]) {
                return false;
            }
          

            charToPositionS[charFromS] = i + 1;
            charToPositionT[charFromT] = i + 1;
        }
      
        return true;
    }
};