class Solution {
private:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (isVowel(words[i].front()) && isVowel(words[i].back()));
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return res;
    }
};