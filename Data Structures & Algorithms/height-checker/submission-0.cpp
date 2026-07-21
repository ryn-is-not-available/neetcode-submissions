class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size(),count=0;
        vector<int> bookkeeping(100,0);
        for(int i=0;i<n;i++){
            bookkeeping[heights[i]-1]++;
        }
        for(int i=0,j=0;i<n;i++){
            while(!bookkeeping[j])j++;
            if(heights[i]!=(j+1))count++;
            bookkeeping[j]--;
        }
        return count;
    }
};