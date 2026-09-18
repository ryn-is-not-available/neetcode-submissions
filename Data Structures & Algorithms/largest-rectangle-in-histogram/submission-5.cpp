class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monoStk;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!monoStk.empty() && heights[monoStk.top()] >= currentHeight) {
                int h = heights[monoStk.top()];
                monoStk.pop();

                int left = monoStk.empty() ? -1 : monoStk.top();
                int width = i - left - 1;

                maxArea = max(maxArea, h * width);
            }
            monoStk.push(i);
        }

        return maxArea;
    }
};