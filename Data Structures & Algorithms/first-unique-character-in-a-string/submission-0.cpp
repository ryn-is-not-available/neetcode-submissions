class Solution {
public:
    int firstUniqChar(string s) {
        int carac[26] = {0};
        
        for(char ch : s){
            carac[ch-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(carac[s[i]-'a']==1) return i;
        }
        return -1;
    }
};