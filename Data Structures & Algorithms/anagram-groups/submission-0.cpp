class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> check(26,0);
        map<vector<int>,vector<string>> matches;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                check[strs[i][j]-'a']++;
            }
            if(matches.contains(check)) matches[check].push_back(strs[i]);
            else matches[check]={strs[i]};
            for(int z=0;z<26;z++){check[z]=0;}
        }
        vector<vector<string>> res;
        for(auto element : matches){
            res.push_back(element.second);
        }
        return res;
    }
};
