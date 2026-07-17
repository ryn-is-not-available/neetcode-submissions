class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = arr.size();
        if (n == 0) return arr;
        int currentRightMax = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            int aux = arr[i];
            arr[i] = currentRightMax;
            currentRightMax = max(currentRightMax, aux); 
        }

        return arr;
    }
};