class Solution {
public:
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i];
            if(vowel.contains(words[i][0]) && vowel.contains(words[i][words[i].size()-1]))prefix[i+1]++;
        }
        vector<int> res(queries.size());

        for(int i=0;i<queries.size();i++){
            res[i]=prefix[queries[i][1]+1]-prefix[queries[i][0]];
        }
        return res;
    }
};