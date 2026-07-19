class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> mapping;
        bool mapped[256] = {false}; 
        
        for (int i = 0; i < s.size(); i++) {
            if (mapping.contains(s[i])) {
                if (mapping[s[i]] != t[i]) return false;
            } else if (mapped[static_cast<unsigned char>(t[i])]) { 
                return false;
            } else {
                mapping[s[i]] = t[i];
                mapped[static_cast<unsigned char>(t[i])] = true;
            }
        }
        return true;
    }
};