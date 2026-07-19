auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool solve(const string& s, const string& t) {
        int mapS[256] = {0};
        int mapT[256] = {0};
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            unsigned char charS = s[i];
            unsigned char charT = t[i];
            
            if (mapS[charS] != mapT[charT]) {
                return false;
            }
            
            mapS[charS] = i + 1;
            mapT[charT] = i + 1;
        }
        
        return true;
    }

    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        return solve(s, t); 
    }
};