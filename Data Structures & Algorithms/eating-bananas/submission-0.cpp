class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() > h ) return -1;
        int left=1,right=-1,eatingRate;

        for(int i=0 ; i<piles.size() ; i++) {
            right=max(right,piles[i]);
        }
        int ans = right;
        while (left <= right) {
            int neededHour = 0 ;
            eatingRate = (left+right)/2;
            for(int pile : piles) {
                neededHour += (pile/eatingRate);
                if(pile%eatingRate) neededHour++;
            }
            if(neededHour <=h){
                ans=min(ans,eatingRate);
                right=eatingRate-1;
                
            }else left=eatingRate+1;
        }
        return ans;
    }
};

