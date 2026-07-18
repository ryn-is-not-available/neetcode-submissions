class Solution {
public:
    int lengthOfLastWord(string s) {
       bool isWord=false;
       int last,i;
       for(i=s.size()-1;i>=0;i--){
            if(!isWord && s[i]!=' '){
                isWord=true;
                last=i;
                continue;
            }
            if(isWord && s[i]==' ') break;
       } 
        return last-i;
    }
};