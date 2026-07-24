class Solution {
public:
    int minOperations(string s) {
        char current=s[s.size()-1];
        int count1=0;
        for(int i=s.size()-2;i>=0;i--){
            if(current==s[i]){
                count1++;
                if(s[i]=='1')current='0';
                else current='1';
            }else{
                current=s[i];
            }
        }
        int count2=s.size()-count1;
        return min(count1,count2);
    }
};