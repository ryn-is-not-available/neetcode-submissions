class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> lastSeen ;
        priority_queue<int> pq;
        vector<int> ans;

        for (int i = 0 ; i < k ; i++) {
            pq.push(nums[i]);
            lastSeen[nums[i]] = i;
        }
        int left=0;
        ans.push_back(pq.top());
        for(int right = k ; right < nums.size() ; right++ ) {
            left++;
            pq.push(nums[right]);
            lastSeen[nums[right]] = right;
            while (lastSeen[pq.top()] < left ) {
                pq.pop();
            }
            ans.push_back(pq.top());
        }

        return ans;
    }
};
