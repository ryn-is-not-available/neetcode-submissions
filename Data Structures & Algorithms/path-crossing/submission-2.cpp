class Solution {
public:
    bool isPathCrossing(string path) {
        // Fast hash set storing encoded 64-bit coordinate pairs
        unordered_set<long long> visited;
        
        int x = 0, y = 0;
        
        auto encode = [](int x, int y) -> long long {
            return ((long long)x << 32) | (unsigned int)y;
        };
        
        visited.insert(encode(0, 0));
        
        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;
            
            long long key = encode(x, y);
            if (visited.count(key)) {
                return true;
            }
            visited.insert(key);
        }
        
        return false;
    }
};