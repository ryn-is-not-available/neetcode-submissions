class Solution {
public:
    int maxScore(string s) {
        int leftscore=0,rightscore=0,best;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1')rightscore++;
        }
        if(s[0]=='0')leftscore++;
        best=leftscore+rightscore;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0'){
                leftscore++;
            }else{
                rightscore--;
            }
            best=max(best,leftscore+rightscore);
        }
        return best;

    }
};