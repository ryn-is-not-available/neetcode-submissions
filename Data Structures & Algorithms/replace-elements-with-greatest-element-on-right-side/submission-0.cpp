class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        if(!n) return arr;
        if(n==1){
            arr[0]=-1;
            return arr;
        }
        int currentRightMax = arr[n-1],aux;
        arr[n-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            aux=arr[i];
            arr[i]=currentRightMax;
            if(aux>currentRightMax){
                currentRightMax=aux;
            }
        }
        return arr;
    }
};