class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 0) {
                // Check if left and right conditions are satisfied
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
                bool right_empty = (i == len - 1 || flowerbed[i + 1] == 0);
                
                if (left_empty && right_empty) {
                    flowerbed[i] = 1; // Place the flower in-place
                    n--;              // Decrement remaining flowers needed
                    
                    if (n <= 0) return true; // Early exit strategy
                }
            }
        }
        
        return n <= 0;
    }
};