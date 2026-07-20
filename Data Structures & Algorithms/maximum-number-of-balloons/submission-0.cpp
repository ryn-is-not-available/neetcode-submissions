class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int carac[26]={0};
        for(int i=0;i<text.size();i++){
            carac[text[i]-'a']++;
        }
        carac['l'-'a']/=2;
        carac['o'-'a']/=2;
        return min({carac['b'-'a'],carac['a'-'a'],carac['l'-'a'],carac['o'-'a'],carac['n'-'a']});
    }
};