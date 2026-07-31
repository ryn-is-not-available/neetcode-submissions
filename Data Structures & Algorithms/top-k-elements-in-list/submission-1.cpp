class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for (auto& [num, count] : freq) {
            min_heap.push({count, num});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        vector<int> res;
        res.reserve(k);
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return res;
    }
};