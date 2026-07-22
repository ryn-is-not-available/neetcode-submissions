class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);

        int carc[26] = {0};
        for (char ch : chars) {
            carc[ch - 'a']++;
        }

        int totalLength = 0;

        for (const string& word : words) {
            int c[26] = {0};
            for (char ch : word) {
                c[ch - 'a']++;
            }

            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (c[i] > carc[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                totalLength += word.size();
            }
        }

        return totalLength;
    }
};