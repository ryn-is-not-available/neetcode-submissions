#include <cstring>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        static int bucket[1000001];
        memset(bucket, 0, sizeof(int) * (target + 1));
        int n = position.size();
        for (int i = 0; i < n; i++) bucket[position[i]] = speed[i];

        int ans = 0;
        long long bn = 0, bd = 1;
        for (int f = target - 1; f >= 0; f--) {
            int s = bucket[f];
            if (!s) continue;
            long long num = target - f;
            if (num * bd > bn * (long long)s) { ans++; bn = num; bd = s; }
        }
        return ans;
    }
};