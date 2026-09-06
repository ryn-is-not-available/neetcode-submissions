class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int missing,left,right;
        
        
        for (int i=0;i<numbers.size();i++) {
            missing = target - numbers[i];
            left=i+1;
            right = numbers.size()-1;
            while(left<=right){
                int mid = (left+right)/2;
                if (numbers[mid]<missing) left = mid + 1;
                else if (numbers[mid]>missing) right = mid - 1;
                else {
                    return {i+1,mid+1};
                }
            }
        }
        return {};  
    }
};
