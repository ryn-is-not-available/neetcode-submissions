class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> GreaterElement;
        int len=nums2.size();
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        stk.push(nums2[len-1]);
        GreaterElement[nums2[len-1]]=-1;
        for(int i=nums2.size()-2;i>=0;i--){
            while(!stk.empty() && nums2[i]>stk.top()){
                stk.pop();
            }
            GreaterElement[nums2[i]]=stk.empty()?-1:stk.top();
            stk.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=GreaterElement[nums1[i]];
        }
        return nums1;

    }
};