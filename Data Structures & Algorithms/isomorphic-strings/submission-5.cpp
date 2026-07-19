class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        // Store the last seen index + 1 (0 means unseen)
        int mapS[256] = {0};
        int mapT[256] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            if (mapS[static_cast<unsigned char>(s[i])] != mapT[static_cast<unsigned char>(t[i])]) {
                return false;
            }
            mapS[static_cast<unsigned char>(s[i])] = i + 1;
            mapT[static_cast<unsigned char>(t[i])] = i + 1;
        }
        
        return true;
    }
};