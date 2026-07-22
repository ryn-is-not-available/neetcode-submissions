class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int carac[26] = {0};
        int total=0;
        for(char c:allowed){
            carac[c-'a']++;
        }
        for(auto word:words){
            bool isValid=true;
            for(char ch : word){
                if(!carac[ch-'a'] && isValid){
                    isValid=false;
                    break;
                }
            }
            if(isValid)total++;
        }
        return total;
    }
};