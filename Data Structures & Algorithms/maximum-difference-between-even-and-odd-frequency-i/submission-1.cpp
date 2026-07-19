#include <climits>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int carac[26] = {0};
        for (char c : s) {
            carac[c - 'a']++;
        }
        
        int max_odd = INT_MIN;
        int min_even = INT_MAX;
        
        for (int i = 0; i < 26; i++) {
            if (carac[i] == 0) continue;
            
            if (carac[i] % 2 != 0) { 
                max_odd = max(max_odd, carac[i]);
            } else { 
                min_even = min(min_even, carac[i]);
            }
        }
        
        if (max_odd == INT_MIN)max_odd=0;
        if(min_even == INT_MAX)min_even=0;
        return max_odd - min_even;
    }
};