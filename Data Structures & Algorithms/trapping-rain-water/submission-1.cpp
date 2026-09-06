class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,leftMax=height[left],right=height.size()-1,rightMax=height[right];
        int trapped=0;
        while (left<right) {
            if(height[left]<leftMax) trapped+= leftMax-height[left];
            else leftMax=height[left];
            
            if(height[right]<rightMax) trapped+= rightMax-height[right];
            else rightMax=height[right];     

            if(leftMax>rightMax) right--;
            else left++;
        }

        return trapped;
    }
};
