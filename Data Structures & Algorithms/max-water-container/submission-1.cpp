class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0,right=heights.size()-1;
        int maxA = -1;
        while (left<right) {
            int currentA = (right-left)*min(heights[left],heights[right]);
            maxA=max(maxA,currentA);
            if (heights[left]<heights[right]) left++;
            else right--;
        }
        return maxA;
    }
};
