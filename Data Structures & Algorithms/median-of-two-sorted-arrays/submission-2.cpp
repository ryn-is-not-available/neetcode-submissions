class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return findMedianSortedArrays(nums2,nums1);

        int n=nums1.size(),m=nums2.size();
        int low = 0 , high = m;
        int half_len = (n+m+1)/2;

        while(low <= high) {
            int i = low +(high -low)/2;
            int j=half_len - i;


            int leftA = (i==0) ? INT_MIN : nums2[i-1];
            int rightA = (i==m) ? INT_MAX : nums2[i];

            int leftB = (j==0) ? INT_MIN : nums1[j-1];
            int rightB = (j==n) ? INT_MAX : nums1[j];

            if (leftA <= rightB && leftB <=rightA) {
                if((n+m)%2==0) return (double)(min(rightA,rightB)+max(leftA,leftB))/2;
                else return max(leftA,leftB);
            }else if (leftA>rightB){
                high = i-1;
            }else {
                low = i+1;
            }
        }
        return -1;
    }
};
