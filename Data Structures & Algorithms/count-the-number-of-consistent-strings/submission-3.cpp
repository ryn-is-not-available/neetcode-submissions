class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int mask = 0;
        for (char c : allowed) {
            mask |= (1 << (c - 'a'));
        }

        int total = 0;
        for (const string& word : words) {
            bool isValid = true;
            for (char ch : word) {
                if (((mask >> (ch - 'a')) & 1) == 0) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) total++;
        }

        return total;
    }
};