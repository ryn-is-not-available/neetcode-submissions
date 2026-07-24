class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int carac[26] = {0};
        for(auto word:words){
            for(char ch:word){
                carac[ch-'a']++;
            }
        }
        int n=words.size();
        for(int i=0;i<26;i++){
            if(carac[i]){
                if(carac[i]%n!=0)return false;
            }
        }
        return true;
    }
};