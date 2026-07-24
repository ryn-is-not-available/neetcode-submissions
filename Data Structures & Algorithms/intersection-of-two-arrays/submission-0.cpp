class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen, res;
        
        for (int num : nums1) {
            seen.insert(num);
        }
        
        for (int num : nums2) {
            if (seen.contains(num)) {
                res.insert(num);
            }
        }
        
        return vector<int>(res.begin(), res.end());
    }
};