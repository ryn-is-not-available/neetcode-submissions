class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> Seen;
        int best=-1;
        for(int i=0;i<s.size();i++){
            if(Seen.contains(s[i])){
                best=max(best,i-Seen[s[i]]-1);
            }else{
                Seen[s[i]]=i;
            }
        }
        return best;
    }
};