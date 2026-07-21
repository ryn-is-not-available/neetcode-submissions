class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]={0};
        int lucky=-1;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]-1]++;
        }
        for(int i=500;i>=0;i--){
            if(freq[i]==i+1)return i+1;
        }
        return -1;
    }
};