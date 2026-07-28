#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> index;
        int n = arr2.size();
        
        for (int i = 0; i < n; i++) {
            index[arr2[i]] = i;
        }

        auto tri = [&](int a, int b) {
            int idx1 = index.contains(a) ? index[a] : n;
            int idx2 = index.contains(b) ? index[b] : n;

            if (idx1 != idx2) {
                return idx1 < idx2;
            }

            return a < b;
        };

        sort(arr1.begin(), arr1.end(), tri);
        return arr1;
    }
};