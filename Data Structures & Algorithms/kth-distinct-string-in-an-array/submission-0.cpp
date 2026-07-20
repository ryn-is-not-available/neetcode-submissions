class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> nbOccurance;
        for(int i=0;i<arr.size();i++){
            nbOccurance[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(nbOccurance[arr[i]]==1){
                k--;
            }
            if(k==0)return arr[i];
        }
        return "";
    }
};