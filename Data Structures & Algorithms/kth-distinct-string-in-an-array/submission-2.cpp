class Solution {
public:
    string kthDistinct(const vector<string>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<string, int> freq;
        freq.reserve(arr.size());
        for (const auto& str : arr) {
            freq[str]++;
        }

        for (const auto& str : arr) {
            if (freq[str] == 1) {
                if (--k == 0) return str;
            }
        }

        return "";
    }
};