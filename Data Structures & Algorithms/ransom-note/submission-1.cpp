class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int carac[26]={0};
        if(ransomNote.size()>magazine.size())return false;

        for(int i=0;i<magazine.size();i++){
            carac[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(--carac[ransomNote[i]-'a']<0)return false;
        }
        return true;
    }
};