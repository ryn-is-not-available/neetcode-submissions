class Solution {
public:
    string largestGoodInteger(string num) {
        string good="",maxGood="";
        int best=0;
        for(int i=0;i<num.size();i++){
            if(good==""){
                good=num[i];
                i++;
            }
            if(good[good.size()-1]==num[i]){
                good+=num[i];
            }else good=num[i];
            if(good.size()==3){
                if(stoi(good)>=best){
                    best=stoi(good);
                    maxGood=good;
                    good="";
                    };
            }
        }
        return maxGood;
    }
};