class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int index=0,size=strs[0].size();
        char c;
        for(int j=0;j<strs[0].size();j++){
            c=strs[0][j];
            for(int i=0;i<strs.size();i++){
                if(j>=strs[i].size() || c!=strs[i][j])return prefix;
            }
            prefix+=c;
            
        }
        return prefix;
    }
};