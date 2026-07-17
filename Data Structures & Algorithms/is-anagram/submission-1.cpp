class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> carc(26, 0);
        int lenS=s.size(),lenT=t.size();
        if(lenS!=lenT) return false;
        for(int i=0;i<lenS;i++){
            carc[s[i]-'a']++;
            carc[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(carc[i]!=0)return false;
        }
        return true;
    }
};
