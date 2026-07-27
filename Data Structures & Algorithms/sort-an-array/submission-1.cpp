class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size(),childIndex,maxIndex;
        // building the heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            int curr = i;
            while (true) {
                int left = 2 * curr + 1;
                int right = 2 * curr + 2;
                int maxIndex = curr;
                if (left < n && nums[left] > nums[maxIndex])maxIndex = left;
                if (right < n && nums[right] > nums[maxIndex])maxIndex = right;
                if (maxIndex == curr)break;
            
                swap(nums[curr], nums[maxIndex]);
                curr=maxIndex;
            }
        }
    

        // sorting it
        for (int i = 0; i < n; i++) {
            int heapSize = n - i - 1;
            swap(nums[0], nums[heapSize]);

            int curr = 0;
            while (true) {
                int left = 2 * curr + 1;
                int right = 2 * curr + 2;
                int maxIndex = curr;

                if (left < heapSize && nums[left] > nums[maxIndex])maxIndex = left;
                if (right < heapSize && nums[right] > nums[maxIndex])maxIndex = right;
                if (maxIndex == curr)break;

                swap(nums[curr], nums[maxIndex]);
                curr = maxIndex;
            }
        }

        return nums;
    }
};
