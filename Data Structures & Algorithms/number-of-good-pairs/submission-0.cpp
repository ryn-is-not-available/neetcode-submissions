class Solution {
public:
    unsigned long long calculateCombination(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
        if (r > n - r) {
        r = n - r;
    }
    
    unsigned long long result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - r + i);
        result /= i;
    }
    return result;
    }
    int numIdenticalPairs(vector<int>& nums) {
        int freq[100]={0},count=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]-1]++;
        }

        for(int i=0;i<100;i++){
            if(freq[i]>=2)count+=calculateCombination(freq[i],2);
        }
        return count;
    }
};