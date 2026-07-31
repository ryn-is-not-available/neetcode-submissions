class Solution {
public:
    string customSortString(string order, string s) {
        int carac[26] = {0};
        for(char ch : s){
            carac[ch-'a']++;
        }
        int j=0;
        for(char ch : order){
            while(carac[ch-'a']){
                s[j]=ch;
                j++;
                carac[ch-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(carac[i]){
                s[j]=(char)('a'+i);
                j++;
                carac[i]--;
            }
        }
        return s;
    }
};